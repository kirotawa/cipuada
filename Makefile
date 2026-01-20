TEST_DIR = tests


.PHONY: run_test clean

run_test:
	@echo "Compiling tests..."
	$(MAKE) -C $(TEST_DIR) tests

clean:
	@echo "Cleaning tests dir..."
	$(MAKE) -C $(TEST_DIR) clean

