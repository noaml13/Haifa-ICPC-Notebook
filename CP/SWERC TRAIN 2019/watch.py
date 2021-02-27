a,b,c,n = map(int, input().split())
if n%2:
	ans = (n * (((n-1)//2) * ((n+1)//2))//2 ) // 3
else:
	ans = (n * (n-2 + (n//2)*(n//2-1)//2 ) ) // 3
if (a==b and b==c):
	pass
elif (a==b or b==c):
	ans*=3
else:
	ans*=6
ans %= 2**64
print(ans)