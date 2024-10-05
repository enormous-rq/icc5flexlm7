import flexlm.*;
import java.io.*;
import java.util.*;

class example2
{
public static void main(String[] argv)
{
    String vendor_name = "demo";
    String feat = "f1";
    String ver = "1.0";
    String licpath = "license.dat";
    String feature;
    int rc;
    license lic;
    byte[] buf = new byte[10];

	if (argv.length == 1) feature = argv[0];
	else feature = feat;
	System.out.println("Checking out feature " + feature);
	lic = new license(vendor_name,  0x12345678^0x0,
					0x87654321^0x0, 
			0x0, 0x0, 0x0, 0x0);
	rc = lic.checkout(LM.RESTRICTIVE /* | LM.RETRY_RESTRICTIVE */, feature,
							ver, 1, licpath);
	if (rc == 0)
	{
		System.out.println("checkout OK");
		hb(lic);
		lic.checkin();
	}
	else
	{
		System.out.println("checkout failed: " + lic.get_errstring());
	}
}

static void hb(license lic)
{
  int[] reconn = new int[1];
  int stat;
  int min = 1;
	while(true)
	{
		stat = lic.heartbeat(reconn, min);
		System.out.println("heartbeat returns " + stat + 
				   ", reconnections = " + reconn[0]);
		try { Thread.sleep((long)(30 * 1000)); }
		catch (InterruptedException e) {System.out.println(e);}
	}
}
}
