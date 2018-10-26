---
title: Classe CSettingsStore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CSettingsStore [MFC], CSettingsStore
- CSettingsStore [MFC], Close
- CSettingsStore [MFC], CreateKey
- CSettingsStore [MFC], DeleteKey
- CSettingsStore [MFC], DeleteValue
- CSettingsStore [MFC], Open
- CSettingsStore [MFC], Read
- CSettingsStore [MFC], Write
ms.assetid: 0ea181de-a13e-4b29-b560-7c43838223ff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 93a56649bb34060c45bf58a621156f46a22682fe
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50075567"
---
# <a name="csettingsstore-class"></a>Classe CSettingsStore

Encapsula as funções de API do Windows, fornecendo uma interface orientada a objeto que você usa para acessar o registro.

## <a name="syntax"></a>Sintaxe

```
class CSettingsStore : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSettingsStore::CSettingsStore](#csettingsstore)|Constrói um objeto `CSettingsStore`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSettingsStore::Close](#close)|Fecha a chave do Registro aberta.|
|[CSettingsStore::CreateKey](#createkey)|Abre a chave especificada ou a cria se ele não existir.|
|[CSettingsStore::DeleteKey](#deletekey)|Exclui a chave especificada e todos os seus filhos.|
|[CSettingsStore::DeleteValue](#deletevalue)|Exclui o valor especificado da chave de abertura.|
|[CSettingsStore::Open](#open)|Abre a chave especificada.|
|[CSettingsStore::Read](#read)|Recupera os dados para um valor de chave especificado.|
|[CSettingsStore::Write](#write)|Grava um valor no registro sob a chave de abertura.|

## <a name="remarks"></a>Comentários

As funções de membro `CreateKey` e `Open` são muito semelhantes. Se a chave do registro já existir, `CreateKey` e `Open` função da mesma maneira. No entanto, se a chave do registro não existir, `CreateKey` vai criá-la enquanto `Open` retornará um valor de erro.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar os métodos de abrir e ler do `CSettingsStore` classe. Este trecho de código faz parte do [amostra de demonstração de dica de ferramenta](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_ToolTipDemo#1](../../mfc/reference/codesnippet/cpp/csettingsstore-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CSettingsStore`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsettingsstore.h

##  <a name="close"></a>  CSettingsStore::Close

Fecha a chave do Registro aberta.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Por padrão, esse método é chamado do destruidor do [classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

##  <a name="createkey"></a>  CSettingsStore::CreateKey

Abre uma chave do registro ou a cria se ele não existir.

```
virtual BOOL CreateKey(LPCTSTR pszPath);
```

### <a name="parameters"></a>Parâmetros

*pszPath*<br/>
[in] Especifica o nome de uma chave a ser criado ou aberto.

### <a name="return-value"></a>Valor de retorno

0 se for bem-sucedido; Caso contrário, um valor diferente de zero.

### <a name="remarks"></a>Comentários

`CreateKey` usa `m_hKey` como a raiz de consultas de registro. Ele procura *pszPath* como uma subchave de `m_hKey`. Se a chave não existir, `CreateKey` o criará. Caso contrário, ele abre a chave. `CreateKey` em seguida, define `m_hKey` à chave criada ou foi aberto.

##  <a name="csettingsstore"></a>  CSettingsStore::CSettingsStore

Cria um objeto `CSettngsStore`.

```
CSettingsStore(
    BOOL bAdmin,
    BOOL bReadOnly);
```

### <a name="parameters"></a>Parâmetros

*bCaminho Admin*<br/>
[in] Parâmetro booleano que especifica se o `CSettingsStore` objeto está funcionando no modo de administrador.

*bReadOnly*<br/>
[in] Parâmetro booleano que especifica se o `CSettingsStore` objeto é criado no modo somente leitura.

### <a name="remarks"></a>Comentários

Se *bCaminho Admin* é definida como TRUE, o `m_hKey` variável de membro é definido como **HKEY_LOCAL_MACHINE**. Se você definir *bCaminho Admin* como FALSE, o `m_hKey` é definido como **HKEY_CURRENT_USER**.

O acesso de segurança depende de *bReadOnly* parâmetro. Se *bReadonly* é FALSE, o acesso de segurança será definido como **KEY_ALL_ACCESS**. Se *bReadyOnly* for TRUE, o acesso de segurança será definido como uma combinação de **KEY_QUERY_VALUE, KEY_NOTIFY** e **KEY_ENUMERATE_SUB_KEYS**. Para obter mais informações sobre o acesso de segurança junto com o registro, consulte [direitos de acesso e segurança de chave do registro](/windows/desktop/SysInfo/registry-key-security-and-access-rights).

O destruidor `CSettingsStore` libera `m_hKey` automaticamente.

##  <a name="deletekey"></a>  CSettingsStore::DeleteKey

Exclui todos os seus filhos e uma chave do registro.

```
virtual BOOL DeleteKey(
    LPCTSTR pszPath,
    BOOL bAdmin = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pszPath*<br/>
[in] O nome da chave a excluir.

*bCaminho Admin*<br/>
[in] Opção que especifica o local da chave a excluir.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método irá falhar se o `CSettingsStore` objeto está no modo somente leitura.

Se o parâmetro *bCaminho Admin* for zero, `DeleteKey` procura a chave excluir sob **HKEY_CURRENT_USER**. Se *bCaminho Admin* for diferente de zero `DeleteKey` procura a chave excluir sob **HKEY_LOCAL_MACHINE**.

##  <a name="deletevalue"></a>  CSettingsStore::DeleteValue

Exclui um valor de `m_hKey`.

```
virtual BOOL DeleteValue(LPCTSTR pszValue);
```

### <a name="parameters"></a>Parâmetros

*pszValue*<br/>
[in] Especifica o campo de valor a ser removido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

##  <a name="open"></a>  CSettingsStore::Open

Abre uma chave do registro.

```
virtual BOOL Open(LPCTSTR pszPath);
```

### <a name="parameters"></a>Parâmetros

*pszPath*<br/>
[in] O nome de uma chave do registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Depois que esse método abre com êxito a chave especificada, ele define `m_hKey` para o identificador dessa chave.

##  <a name="read"></a>  CSettingsStore::Read

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

*pszKey*<br/>
[in] Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser lido do registro.

*iVal*<br/>
[out] Referência a uma variável inteira que recebe o valor lido da chave do registro.

*dwVal*<br/>
[out] Referência a uma variável de palavra dupla de 32 bits que recebe o valor lido da chave do registro.

*sVal*<br/>
[out] Referência a uma variável de cadeia de caracteres que recebe o valor lido da chave do registro.

*scStringList*<br/>
[out] Referência a uma variável de lista de cadeia de caracteres que recebe o valor lido da chave do registro.

*scArray*<br/>
[out] Referência a uma variável de matriz de cadeia de caracteres que recebe o valor lido da chave do registro.

*dwcArray*<br/>
[out] Referência a uma variável de matriz de palavra dupla de 32 bits que recebe o valor lido da chave do registro.

*wcArray*<br/>
[out] Referência a uma variável de matriz de palavras de 16 bits que recebe o valor lido da chave do registro.

*bcArray*<br/>
[out] Referência a uma variável de matriz de bytes que recebe o valor lido da chave do registro.

*lpPoint*<br/>
[out] Referência a um ponteiro para um `POINT` ler de estrutura que recebe o valor da chave do registro.

*Rect*<br/>
[out] Referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) ler de variável que recebe o valor da chave do registro.

*ppData*<br/>
[out] Leitura de ponteiro para um ponteiro para dados que recebe o valor da chave do registro.

*Petabytes*<br/>
[out] Ponteiro para uma variável de inteiro sem sinal. Essa variável recebe o tamanho do buffer que *ppData* aponta.

*list*<br/>
[out] Referência a um [CObList](../../mfc/reference/coblist-class.md) ler de variável que recebe o valor da chave do registro.

*obj*<br/>
[out] Referência a um [CObject](../../mfc/reference/cobject-class.md) ler de variável que recebe o valor da chave do registro.

*pObj*<br/>
[out] Referência a um ponteiro para um `CObject` ler de variável que recebe o valor da chave do registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

`Read` verifica se há *pszKey* como uma subchave de `m_hKey`.

##  <a name="write"></a>  CSettingsStore::Write

Grava um valor no registro sob a chave de abertura.

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

*pszKey*<br/>
[in] Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido.

*iVal*<br/>
[in] Referência a uma variável de inteiro que contém os dados serem armazenados.

*dwVal*<br/>
[in] Referência a uma variável de palavra dupla de 32 bits que contém os dados serem armazenados.

*pszVal*<br/>
[in] Ponteiro para uma variável de cadeia de caracteres terminada em nulo que contém os dados serem armazenados.

*scStringList*<br/>
[in] Referência a um [CStringList](../../mfc/reference/cstringlist-class.md) variável que contém os dados serem armazenados.

*bcArray*<br/>
[in] Referência a uma variável de matriz de bytes que contém os dados serem armazenados.

*scArray*<br/>
[in] Referência a uma variável de matriz de cadeia de caracteres que contém os dados serem armazenados.

*dwcArray*<br/>
[in] Referência a uma variável de matriz de palavra dupla de 32 bits que contém os dados serem armazenados.

*wcArray*<br/>
[in] Referência a uma variável de matriz de palavras de 16 bits que contém os dados para armazenar.

*Rect*<br/>
[in] Referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) variável que contém os dados serem armazenados.

*lpPoint*<br/>
[in] Referência a um ponteiro para um `POINT` variável que contém os dados serem armazenados.

*pData*<br/>
[in] Ponteiro para um buffer que contém os dados serem armazenados.

*nBytes*<br/>
[in] Especifica o tamanho, em bytes, dos dados ao qual o *pData* pontos de parâmetro.

*list*<br/>
[in] Referência a um [CObList](../../mfc/reference/coblist-class.md) variável que contém os dados serem armazenados.

*obj*<br/>
[in] Referência a um [CObject](../../mfc/reference/cobject-class.md) variável que contém os dados serem armazenados.

*pObj*<br/>
[in] Ponteiro para um ponteiro para um `CObject` variável que contém os dados serem armazenados.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para gravar no registro, você deve definir *bReadOnly* como um valor diferente de zero quando você cria um [CSettingsStore](../../mfc/reference/csettingsstore-class.md) objeto. Para obter mais informações, consulte [CSettingsStore::CSettingsStore](#csettingsstore).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)
