
#pragma once

#include <credentialprovider.h>

class OVirtCredentials : public ICredentialProviderCredential
{
	public:

		OVirtCredentials();

		HRESULT Initialize(const CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR* rgcpfd,
			/*const FIELD_STATE_PAIR* rgfsp,*/
			PCWSTR pwzUsername,
			PCWSTR pwzPassword,
			PCWSTR pwzDomainName);

			// IUnknown

		IFACEMETHODIMP_(ULONG) AddRef();
		IFACEMETHODIMP_(ULONG) Release();
		IFACEMETHODIMP QueryInterface(__in REFIID riid, __deref_out void** ppv);
    
			// ICredentialProviderCredential

		IFACEMETHODIMP Advise(__in ICredentialProviderCredentialEvents* pcpce);
		IFACEMETHODIMP UnAdvise();
		IFACEMETHODIMP SetSelected(__out BOOL* pbAutoLogon);
		IFACEMETHODIMP SetDeselected();
		IFACEMETHODIMP GetFieldState(__in DWORD dwFieldID,
			__out CREDENTIAL_PROVIDER_FIELD_STATE* pcpfs,
			__out CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE* pcpfis);
		IFACEMETHODIMP GetStringValue(__in DWORD dwFieldID, __deref_out PWSTR* ppwsz);
		IFACEMETHODIMP GetBitmapValue(__in DWORD dwFieldID, __out HBITMAP* phbmp);
		IFACEMETHODIMP GetCheckboxValue(__in DWORD dwFieldID, __out BOOL* pbChecked,
			__deref_out PWSTR* ppwszLabel);
		IFACEMETHODIMP GetComboBoxValueCount(__in DWORD dwFieldID, 
			__out DWORD* pcItems, __out_range(<,*pcItems) DWORD* pdwSelectedItem);
		IFACEMETHODIMP GetComboBoxValueAt(__in DWORD dwFieldID, __in DWORD dwItem, 
			__deref_out PWSTR* ppwszItem);
		IFACEMETHODIMP GetSubmitButtonValue(__in DWORD dwFieldID, 
			__out DWORD* pdwAdjacentTo);
		IFACEMETHODIMP SetStringValue(__in DWORD dwFieldID, __in PCWSTR pwz);
		IFACEMETHODIMP SetCheckboxValue(__in DWORD dwFieldID, __in BOOL bChecked);
		IFACEMETHODIMP SetComboBoxSelectedValue(__in DWORD dwFieldID,
			__in DWORD dwSelectedItem);
		IFACEMETHODIMP CommandLinkClicked(__in DWORD dwFieldID);
		IFACEMETHODIMP GetSerialization(__out CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE* pcpgsr, 
			__out CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs, 
			__deref_out_opt PWSTR* ppwszOptionalStatusText, 
			__out CREDENTIAL_PROVIDER_STATUS_ICON* pcpsiOptionalStatusIcon);
		IFACEMETHODIMP ReportResult(__in NTSTATUS ntsStatus, __in NTSTATUS ntsSubstatus,
			__deref_out_opt PWSTR* ppwszOptionalStatusText, 
			__out CREDENTIAL_PROVIDER_STATUS_ICON* pcpsiOptionalStatusIcon);

		bool GotCredentials();
		void SetCredentials(LPCWSTR wzUserName, LPCWSTR wzPassword, LPCWSTR wzDomain);
		void ResetCredentials();
		void SetUsageScenario(CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus);

	protected:

			~OVirtCredentials();

	private:
		LONG _cRef;
		CREDENTIAL_PROVIDER_USAGE_SCENARIO _cpus;
		PWSTR _wzUserName;
		PWSTR _wzDomain;
		PWSTR _wzPassword;
};
