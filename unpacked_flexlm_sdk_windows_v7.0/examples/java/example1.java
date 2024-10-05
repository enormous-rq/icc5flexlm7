import flexlm.*;
import java.io.*;

class example1
{
	public static void main(String[] argv)
	{
	    String vendor_name = "demo";
	    String feat = "f1";
	    String ver = "1.0";
	    String licpath = "license.dat";
	    String feature;
	    int rc;
	    byte buf[] = new byte[10];
	    license lic;

		if (argv.length == 1) feature = argv[0];
		else feature = feat;
		System.out.println("Checking out feature " + feature);
		lic = new license(vendor_name,  0x12345678^0x0,
						0x87654321^0x0, 
			0x0, 0x0, 0x0, 0x0);
		rc = lic.checkout(LM.RESTRICTIVE, feature, ver, 1, licpath);
		if (rc == 0)
		{
			System.out.println("checkout OK, press return to checkin ");
			try { System.in.read(buf); }
			catch (IOException e) {}
			lic.checkin();
		}
		else
		{
			System.out.println("checkout failed: " +
							lic.get_errstring());
		}
	}
}
