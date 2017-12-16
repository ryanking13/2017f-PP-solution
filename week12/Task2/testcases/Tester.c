#include <stdio.h> 
#include <math.h> 
typedef int bool;
enum {false, true};
bool finding_solution(int* answer, long long a, long long b, long long c, long long d, double min, double max)
{
	double min_value = a * min * min * min +
		b * min * min +
		c * min +
		d;

	double max_value = a * max * max * max +
		b * max * max +
		c * max +
		d;

	double mid = ((min + max) / 2.0);

	double mid_value = a * mid * mid * mid +
		b * mid * mid +
		c * mid +
		d;

	if (max - min < 2)
	{
		int answer_;
		if ((int)min == min / 1.0)
			answer_ = min;
		else
			answer_ = min + 1;

		long long answer_value = a * answer_ * answer_ * answer_ +
			b * answer_ * answer_ +
			c * answer_ +
			d;
		for (int i = 1; i <= 2; i++)
		{
			if (answer_value == 0) {
				*answer = answer_;
				return true;
			}
			answer_ += 1;
			answer_value = a * answer_ * answer_ * answer_ +
				b * answer_ * answer_ +
				c * answer_ +
				d;
		}
		return false;
	}


	if ((min_value > 0 && max_value > 0) || (min_value < 0 && max_value < 0))
		return false;

	if ((mid_value >= 0 && max_value <= 0) || (mid_value <= 0 && max_value >= 0))
		return finding_solution(answer, a, b, c, d, mid, max);
	else
		return finding_solution(answer, a, b, c, d, min, mid);
}
int main()
{
	//3�� ������  
	//f(x) = ax^3 + bx^2 + cx + d 

	//f'(x) = 3ax^2 + 2bx + c 
	//f'(x)�� �� : [-2b +- sqrt(4b^2 - 12ac)] / 6a 


	long long  a, b, c, d;
	long long det;

	int n;
	scanf("%d", &n);

	while (scanf("%lld %lld %lld %lld", &a, &b, &c, &d) != EOF) {
		if (a < 0)
		{
			a = -a; 
			b = -b; 
			c = -c; 
			d = -d;
		}
		det = 4 * b*b - 12 * a*c;
		int answer = -111111;
		//f'(x) ���� 2�� �� ��  
		if (det > 0) {
			double tmp = sqrt(4 * b*b - 12 * a * c);
			double extreme1 = (-2 * b - sqrt(4 * b*b - 12 * a * c)) / (6 * a);
			double extreme2 = (-2 * b + sqrt(4 * b*b - 12 * a * c)) / (6 * a);
			int answer1 = -1111111;
			int answer2 = -1111111;
			if (finding_solution(&answer, a, b, c, d, 0, extreme1))
				printf("%d ", answer);

			if (finding_solution(&answer1, a, b, c, d, extreme1, extreme2))
			{
				if (answer1 != answer)
					printf("%d ", answer1);
			}
			if (finding_solution(&answer2, a, b, c, d, extreme2, 10000))
				if (answer2 != answer1 && answer2 != answer)
					printf("%d ", answer2);
			printf("\n");
		}

		//f'(x) ���� 1�� �� ��  
		else if (det == 0) {
			if (finding_solution(&answer, a, b, c, d, 0, 10000))
				printf("%d\n", answer);
		}
		//f'(x) ���� 0�� �� ��  
		else if (det < 0) {
			if (finding_solution(&answer, a, b, c, d, 0, 10000))
				printf("%d\n", answer);
		}

	}
	//printf("ANSWER : %f\n", answer); 
	return 0;
}
