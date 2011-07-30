/* Calculates the wins for each type, calculate the rest manually. */
#include <iostream>
#include <vector>
#include <gmpxx.h>

using namespace std;

class dice {
private:
	vector<vector<unsigned short> > _rolls;
	unsigned short _eyes;
	unsigned short _diecount;

	void generate_rolls() {

	}
public:
	dice(unsigned short eyes, unsigned short diecount) {
		if (eyes < 1)
			throw "eyes < 1";
		if (diecount < 1)
			throw "diecount < 1";
		_eyes = eyes;
		_diecount = diecount;
		generate_rolls();
	}
};

int main(int argc, char **argv) {
	mpz_class pwin("0");
	mpz_class cwin("0");
	mpz_class draw("0");
	for (unsigned short p1 = 1; p1 <= 4; p1++)
		for (unsigned short p2 = 1; p2 <= 4; p2++)
			for (unsigned short p3 = 1; p3 <= 4; p3++)
				for (unsigned short p4 = 1; p4 <= 4; p4++)
					for (unsigned short p5 = 1; p5 <= 4; p5++)
						for (unsigned short p6 = 1; p6 <= 4; p6++)
							for (unsigned short p7 = 1; p7 <= 4; p7++)
								for (unsigned short p8 = 1; p8 <= 4; p8++)
									for (unsigned short p9 = 1; p9 <= 4; p9++) {
										unsigned short psum = p1 + p2 + p3 + p4
												+ p5 + p6 + p7 + p8 + p9;
										for (unsigned short c1 = 1; c1 <= 6;
												c1++)
											for (unsigned short c2 = 1; c2 <= 6;
													c2++)
												for (unsigned short c3 = 1;
														c3 <= 6; c3++)
													for (unsigned short c4 = 1;
															c4 <= 6; c4++)
														for (unsigned short c5 =
																1; c5 <= 6;
																c5++)
															for (unsigned short c6 =
																	1; c6 <= 6;
																	c6++) {
																unsigned short csum =
																		c1 + c2
																				+ c3
																				+ c4
																				+ c5
																				+ c6;
																if (csum > psum)
																	cwin++;
																else if (psum
																		> csum)
																	pwin++;
																else
																	draw++;
															}
									}
	cout << "pwin: " << pwin << endl;
	cout << "cwin: " << cwin << endl;
	cout << "draw: " << draw << endl;
	return 0;
}
