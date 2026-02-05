# 定义编译器
CXX = g++

# 定义编译参数：这里加上 GBK 转换，解决你的乱码问题
CXXFLAGS = -fexec-charset=GBK

# 这是一个通用规则 (Implicit Rule)
# %: %.cpp 的意思是：当我想构建 "xxx" 时，自动去找 "xxx.cpp"
%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)
	@echo [Run] ------------------------------
	@.\$@.exe
	@echo ------------------------------------