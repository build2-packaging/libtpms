#include <libtpms/tpm_error.h>
#include <libtpms/tpm_library.h>

#undef NDEBUG
#include <assert.h>

int
main(void) {
    assert(TPMLIB_ChooseTPMVersion(TPMLIB_TPM_VERSION_2) == TPM_SUCCESS);
    assert(TPMLIB_MainInit() == TPM_SUCCESS);
    TPMLIB_Terminate();

    return 0;
}
