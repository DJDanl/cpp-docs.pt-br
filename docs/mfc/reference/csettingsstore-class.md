---
title: Classe CSettingsStore | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSettingsStore
- AFXSETTINGSSTORE/CSettingsStore
- AFXSETTINGSSTORE/CSettingsStore::CSettingsStore
- AFXSETTINGSSTORE/CSettingsStore::Close
- AFXSETTINGSSTORE/CSettingsStore::CreateKey
- AFXSETTINGSSTORE/CSettingsStore::DeleteKey
- AFXSETTINGSSTORE/CSettingsStore::DeleteValue
- AFXSETTINGSSTORE/CSettingsStore::Open
- AFXSETTINGSSTORE/CSettingsStore::Read
- AFXSETTINGSSTORE/CSettingsStore::Write
dev_langs:
- C++
helpviewer_keywords:
- CSettingsStore class
ms.assetid: 0ea181de-a13e-4b29-b560-7c43838223ff
caps.latest.revision: 29
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0b07f6b12e178d8e324313ea3b0f6de9ae7420c9
ms.openlocfilehash: 0918c8dd9b6284adecb61bc95ddfd41c22d16cb8
ms.lasthandoff: 02/25/2017

---
# <a name="csettingsstore-class"></a>Classe CSettingsStore
Encapsula as funções de API do Windows, fornecendo uma interface orientada a objeto que você usa para acessar o registro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSettingsStore : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSettingsStore::CSettingsStore](#csettingsstore)|Constrói um objeto `CSettingsStore`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSettingsStore::Close](#close)|Fecha a chave do Registro aberta.|  
|[CSettingsStore::CreateKey](#createkey)|Abre a chave especificada ou cria se ele não existir.|  
|[CSettingsStore::DeleteKey](#deletekey)|Exclui a chave especificada e todos os seus filhos.|  
|[CSettingsStore::DeleteValue](#deletevalue)|Exclui o valor especificado da chave aberta.|  
|[CSettingsStore::Open](#open)|Abre a chave especificada.|  
|[CSettingsStore::Read](#read)|Recupera os dados para um valor de chave especificado.|  
|[CSettingsStore::Write](#write)|Grava um valor do registro na chave aberta.|  
  
## <a name="remarks"></a>Comentários  
 As funções de membro `CreateKey` e `Open` são muito semelhantes. Se a chave do registro já existir, `CreateKey` e `Open` função da mesma maneira. No entanto, se a chave do registro não existir, `CreateKey` irá criá-lo enquanto `Open` retornará um valor de erro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar os métodos de abrir e ler do `CSettingsStore` classe. Este trecho de código é parte do [exemplo de demonstração de dica de ferramenta](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_ToolTipDemo n º&1;](../../mfc/reference/codesnippet/cpp/csettingsstore-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CSettingsStore`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxsettingsstore.h  
  
##  <a name="close"></a>CSettingsStore::Close  
 Fecha a chave do Registro aberta.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método é chamado do destruidor do [CSettingsStore classe](../../mfc/reference/csettingsstore-class.md).  
  
##  <a name="createkey"></a>CSettingsStore::CreateKey  
 Abre uma chave do registro ou cria se ele não existir.  
  
```  
virtual BOOL CreateKey(LPCTSTR pszPath);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pszPath`  
 Especifica o nome de uma chave a ser criado ou aberto.  
  
### <a name="return-value"></a>Valor de retorno  
 0 se for bem-sucedido; Caso contrário, um valor diferente de zero.  
  
### <a name="remarks"></a>Comentários  
 `CreateKey`usa `m_hKey` como a raiz de consultas do registro. Ele procura `pszPath` como uma subchave da `m_hKey`. Se a chave não existir, `CreateKey` cria. Caso contrário, ele abre a chave. `CreateKey`define `m_hKey` à chave aberto ou criado.  
  
##  <a name="csettingsstore"></a>CSettingsStore::CSettingsStore  
 Cria um objeto `CSettngsStore`.  
  
```  
CSettingsStore(
    BOOL bAdmin,  
    BOOL bReadOnly);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAdmin`  
 Parâmetro booleano que especifica se o `CSettingsStore` objeto está funcionando no modo de administrador.  
  
 [in] `bReadOnly`  
 Parâmetro booleano que especifica se o `CSettingsStore` objeto é criado no modo somente leitura.  
  
### <a name="remarks"></a>Comentários  
 Se `bAdmin` é definido como `false`, o `m_hKey` variável de membro é definido como `HKEY_LOCAL_MACHINE`. If you set `bAdmin` to `true`, `m_hKey` is set to `HKEY_CURRENT_USER`.  
  
 O acesso de segurança depende do `bReadOnly` parâmetro. Se `bReadonly` é `false`, a segurança de acesso será definida como `KEY_ALL_ACCESS`. Se `bReadyOnly` é `true`, o acesso de segurança será definido como uma combinação de `KEY_QUERY_VALUE, KEY_NOTIFY` e `KEY_ENUMERATE_SUB_KEYS`. Para obter mais informações sobre o acesso de segurança junto com o registro, consulte [direitos de acesso e segurança de chave do registro](http://msdn.microsoft.com/library/windows/desktop/ms724878).  
  
 O destruidor de `CSettingsStore` libera `m_hKey` automaticamente.  
  
##  <a name="deletekey"></a>CSettingsStore::DeleteKey  
 Exclui todos os seus filhos e uma chave do registro.  
  
```  
virtual BOOL DeleteKey(
    LPCTSTR pszPath,  
    BOOL bAdmin = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pszPath`  
 O nome da chave a excluir.  
  
 [in] `bAdmin`  
 Opção que especifica o local da chave a excluir.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método irá falhar se o `CSettingsStore` objeto está no modo somente leitura.  
  
 Se o parâmetro `bAdmin` for zero, `DeleteKey` procura a chave excluir em `HKEY_CURRENT_USER`. Se `bAdmin` é diferente de zero, `DeleteKey` procura a chave excluir em `HKEY_LOCAL_MACHINE`.  
  
##  <a name="deletevalue"></a>CSettingsStore::DeleteValue  
 Exclui um valor de `m_hKey`.  
  
```  
virtual BOOL DeleteValue(LPCTSTR pszValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pszValue`  
 Especifica o campo de valor para remover.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="open"></a>CSettingsStore::Open  
 Abre uma chave do registro.  
  
```  
virtual BOOL Open(LPCTSTR pszPath);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pszPath`  
 O nome de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Depois que esse método abre com êxito a chave especificada, ele define `m_hKey` para tratar dessa chave.  
  
##  <a name="read"></a>CSettingsStore::Read  
 Lê um valor de uma chave do registro.  
  
```  
virtual BOOL Read(
    LPCTSTR pszKey,  
    int& iVal);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    DWORD& dwVal);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CString& sVal);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CStringList& scStringList);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CStringArray& scArray);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CDWordArray& dwcArray);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CWordArray& wcArray);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CByteArray& bcArray);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    LPPOINT& lpPoint);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CRect& rect);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    BYTE** ppData,  
    UINT* pBytes);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CObList& list);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CObject& obj);

 
virtual BOOL Read(
    LPCTSTR pszKey,  
    CObject*& pObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pszKey`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser lidas no registro.  
  
 [out] `iVal`  
 Referência a uma variável de inteiro que recebe o valor da chave do registro de leitura.  
  
 [out] `dwVal`  
 Referência a uma variável de palavra dupla de 32 bits que recebe o valor da chave do registro de leitura.  
  
 [out] `sVal`  
 Referência a uma variável de cadeia de caracteres que recebe o valor da chave do registro de leitura.  
  
 [out] `scStringList`  
 Referência a uma variável de lista de cadeia de caracteres que recebe o valor da chave do registro de leitura.  
  
 [out] `scArray`  
 Referência a uma variável de matriz de cadeia de caracteres que recebe o valor da chave do registro de leitura.  
  
 [out] `dwcArray`  
 Referência a uma variável de matriz de palavra dupla de 32 bits que recebe o valor da chave do registro de leitura.  
  
 [out] `wcArray`  
 Referência a uma variável de matriz de palavra de 16 bits que recebe o valor da chave do registro de leitura.  
  
 [out] `bcArray`  
 Referência a uma variável de matriz de bytes que recebe o valor da chave do registro de leitura.  
  
 [out] `lpPoint`  
 Referência a um ponteiro para um `POINT` ler estrutura que recebe o valor da chave do registro.  
  
 [out] `rect`  
 Referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) ler variável que recebe o valor da chave do registro.  
  
 [out] `ppData`  
 Leitura de ponteiro para um ponteiro para dados que recebe o valor da chave do registro.  
  
 [out] `pBytes`  
 Ponteiro para uma variável de inteiro não assinado. Essa variável recebe o tamanho do buffer que `ppData` aponta.  
  
 [out] `list`  
 Referência a um [CObList](../../mfc/reference/coblist-class.md) ler variável que recebe o valor da chave do registro.  
  
 [out] `obj`  
 Referência a um [CObject](../../mfc/reference/cobject-class.md) ler variável que recebe o valor da chave do registro.  
  
 [out] `pObj`  
 Referência a um ponteiro para um `CObject` ler variável que recebe o valor da chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 `Read`verifica se há `pszKey` como uma subchave da `m_hKey`.  
  
##  <a name="write"></a>CSettingsStore::Write  
 Grava um valor do registro na chave aberta.  
  
```  
virtual BOOL Write(
    LPCTSTR pszKey,  
    int iVal);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    DWORD dwVal);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    LPCTSTR pszVal);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    CStringList& scStringList);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    CByteArray& bcArray);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    CStringArray& scArray);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    CDWordArray& dwcArray);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    CWordArray& wcArray);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    const CRect& rect);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    LPPOINT& lpPoint);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    LPBYTE pData,  
    UINT nBytes);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    CObList& list);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    CObject& obj);

 
virtual BOOL Write(
    LPCTSTR pszKey,  
    CObject* pObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pszKey`  
 Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido.  
  
 [in] `iVal`  
 Referência a uma variável de inteiro que contém os dados a serem armazenados.  
  
 [in] `dwVal`  
 Referência a uma variável de palavra dupla de 32 bits que contém os dados a serem armazenados.  
  
 [in] `pszVal`  
 Ponteiro para uma variável de cadeia de caracteres terminada em nulo que contém os dados a serem armazenados.  
  
 [in] `scStringList`  
 Referência a um [CStringList](../../mfc/reference/cstringlist-class.md) variável que contém os dados a serem armazenados.  
  
 [in] `bcArray`  
 Referência a uma variável de matriz de bytes que contém os dados a serem armazenados.  
  
 [in] `scArray`  
 Referência a uma variável de matriz de cadeia de caracteres que contém os dados a serem armazenados.  
  
 [in] `dwcArray`  
 Referência a uma variável de matriz de palavra dupla de 32 bits que contém os dados a serem armazenados.  
  
 [in] `wcArray`  
 Referência a uma variável de matriz de palavra de 16 bits que contém os dados a serem armazenados.  
  
 [in] `rect`  
 Referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) variável que contém os dados a serem armazenados.  
  
 [in] `lpPoint`  
 Referência a um ponteiro para um `POINT` variável que contém os dados a serem armazenados.  
  
 [in] `pData`  
 Ponteiro para um buffer que contém os dados a serem armazenados.  
  
 [in] `nBytes`  
 Especifica o tamanho, em bytes, dos dados para o qual o `pData` pontos de parâmetro.  
  
 [in] `list`  
 Referência a um [CObList](../../mfc/reference/coblist-class.md) variável que contém os dados a serem armazenados.  
  
 [in] `obj`  
 Referência a um [CObject](../../mfc/reference/cobject-class.md) variável que contém os dados a serem armazenados.  
  
 [in] `pObj`  
 Ponteiro para um ponteiro para um `CObject` variável que contém os dados a serem armazenados.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` caso bem-sucedido; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Para gravar no registro, você deve definir `bReadOnly` para um valor diferente de zero quando você cria um [CSettingsStore](../../mfc/reference/csettingsstore-class.md) objeto. Para obter mais informações, consulte [CSettingsStore::CSettingsStore](#csettingsstore).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)

