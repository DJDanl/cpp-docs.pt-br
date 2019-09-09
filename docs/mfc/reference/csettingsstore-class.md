---
title: Classe CSettingsStore
ms.date: 11/04/2016
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
ms.openlocfilehash: 75d86b81d9651e5892913af5919ae0a78fe6bbc5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502918"
---
# <a name="csettingsstore-class"></a>Classe CSettingsStore

Encapsula as funções da API do Windows, fornecendo uma interface orientada a objeto que você usa para acessar o registro.

## <a name="syntax"></a>Sintaxe

```
class CSettingsStore : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSettingsStore::CSettingsStore](#csettingsstore)|Constrói um objeto `CSettingsStore`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSettingsStore::Close](#close)|Fecha a chave do registro aberto.|
|[CSettingsStore::CreateKey](#createkey)|Abre a chave especificada ou a cria caso ela não exista.|
|[CSettingsStore::DeleteKey](#deletekey)|Exclui a chave especificada e todos os seus filhos.|
|[CSettingsStore::DeleteValue](#deletevalue)|Exclui o valor especificado da chave aberta.|
|[CSettingsStore::Open](#open)|Abre a chave especificada.|
|[CSettingsStore::Read](#read)|Recupera os dados para um valor de chave especificado.|
|[CSettingsStore::Write](#write)|Grava um valor no registro na chave aberta.|

## <a name="remarks"></a>Comentários

As funções `CreateKey` member e `Open` são muito semelhantes. Se a chave do registro já existir `CreateKey` e `Open` funcionar da mesma maneira. No entanto, se a chave do registro não `CreateKey` existir, ela será `Open` criada enquanto retornará um valor de erro.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar os métodos Open e Read da `CSettingsStore` classe. Este trecho de código faz parte do [exemplo de demonstração da dica de ferramenta](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_ToolTipDemo#1](../../mfc/reference/codesnippet/cpp/csettingsstore-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CSettingsStore`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsettingsstore. h

##  <a name="close"></a>  CSettingsStore::Close

Fecha a chave do registro aberto.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Por padrão, esse método é chamado a partir do destruidor da [classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

##  <a name="createkey"></a>  CSettingsStore::CreateKey

Abre uma chave do registro ou a cria se ela não existir.

```
virtual BOOL CreateKey(LPCTSTR pszPath);
```

### <a name="parameters"></a>Parâmetros

*pszPath*<br/>
no Especifica o nome de uma chave a ser criada ou aberta.

### <a name="return-value"></a>Valor de retorno

0 se for bem-sucedido; caso contrário, um valor diferente de zero.

### <a name="remarks"></a>Comentários

`CreateKey`usa `m_hKey` como a raiz das consultas de registro. Ele procura *pszPath* como uma subchave de `m_hKey`. Se a chave não existir, `CreateKey` a criará. Caso contrário, ele abrirá a chave. `CreateKey`em seguida `m_hKey` , define para a chave criada ou aberta.

##  <a name="csettingsstore"></a>CSettingsStore::CSettingsStore

Cria um objeto `CSettngsStore`.

```
CSettingsStore(
    BOOL bAdmin,
    BOOL bReadOnly);
```

### <a name="parameters"></a>Parâmetros

*bAdmin*<br/>
no Parâmetro booliano que especifica se `CSettingsStore` o objeto está agindo no modo de administrador.

*bReadOnly*<br/>
no Parâmetro booliano que especifica se `CSettingsStore` o objeto é criado no modo somente leitura.

### <a name="remarks"></a>Comentários

Se *bAdmin* for definido como true, a `m_hKey` variável de membro será definida como **HKEY_LOCAL_MACHINE**. Se você definir *bAdmin* como false, `m_hKey` será definido como **HKEY_CURRENT_USER**.

O acesso de segurança depende do parâmetro *bReadOnly* . Se *bReadOnly* for false, o acesso de segurança será definido como **KEY_ALL_ACCESS**. Se *bReadyOnly* for true, o acesso de segurança será definido como uma combinação de **KEY_QUERY_VALUE, KEY_NOTIFY** e **KEY_ENUMERATE_SUB_KEYS**. Para obter mais informações sobre o acesso de segurança junto com o registro, consulte [segurança da chave do registro e direitos de acesso](/windows/win32/SysInfo/registry-key-security-and-access-rights).

O destruidor `CSettingsStore` é liberado `m_hKey` automaticamente.

##  <a name="deletekey"></a>  CSettingsStore::DeleteKey

Exclui uma chave e todos os seus filhos do registro.

```
virtual BOOL DeleteKey(
    LPCTSTR pszPath,
    BOOL bAdmin = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pszPath*<br/>
no O nome da chave a ser excluída.

*bAdmin*<br/>
no Opção que especifica o local da chave a ser excluída.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método falhará se o `CSettingsStore` objeto estiver no modo somente leitura.

Se o parâmetro *bAdmin* for zero, `DeleteKey` o procurará a chave a ser excluída em **HKEY_CURRENT_USER**. Se *bAdmin* for diferente de `DeleteKey` zero, o procurará a chave a ser excluída em **HKEY_LOCAL_MACHINE**.

##  <a name="deletevalue"></a>  CSettingsStore::DeleteValue

Exclui um valor de `m_hKey`.

```
virtual BOOL DeleteValue(LPCTSTR pszValue);
```

### <a name="parameters"></a>Parâmetros

*pszValue*<br/>
no Especifica o campo de valor a ser removido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="open"></a>  CSettingsStore::Open

Abre uma chave do registro.

```
virtual BOOL Open(LPCTSTR pszPath);
```

### <a name="parameters"></a>Parâmetros

*pszPath*<br/>
no O nome de uma chave do registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Depois que esse método abrir com êxito a chave especificada, ele `m_hKey` será definido como o identificador dessa chave.

##  <a name="read"></a>  CSettingsStore::Read

Lê um valor de uma chave no registro.

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
no Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser lido no registro.

*iVal*<br/>
fora Referência a uma variável de inteiro que recebe o valor lido da chave do registro.

*dwVal*<br/>
fora Referência a uma variável de palavra dupla de 32 bits que recebe o valor lido da chave do registro.

*sVal*<br/>
fora Referência a uma variável de cadeia de caracteres que recebe o valor lido da chave do registro.

*scStringList*<br/>
fora Referência a uma variável de lista de cadeia de caracteres que recebe o valor lido da chave do registro.

*scArray*<br/>
fora Referência a uma variável de matriz de cadeia de caracteres que recebe o valor lido da chave do registro.

*dwcArray*<br/>
fora Referência a uma variável de matriz de palavras duplas de 32 bits que recebe o valor lido da chave do registro.

*wcArray*<br/>
fora Referência a uma variável de matriz de palavras de 16 bits que recebe o valor lido da chave do registro.

*bcArray*<br/>
fora Referência a uma variável de matriz de bytes que recebe o valor lido da chave do registro.

*lpPoint*<br/>
fora Referência a um ponteiro para uma `POINT` estrutura que recebe o valor lido da chave do registro.

*rect*<br/>
fora Referência a uma variável [CRect](../../atl-mfc-shared/reference/crect-class.md) que recebe o valor lido da chave do registro.

*ppData*<br/>
fora Ponteiro para um ponteiro para dados que recebe o valor lido da chave do registro.

*pBytes*<br/>
fora Ponteiro para uma variável de inteiro sem sinal. Essa variável recebe o tamanho do buffer para o qual *ppData* aponta.

*list*<br/>
fora Referência a uma variável [CObList](../../mfc/reference/coblist-class.md) que recebe o valor lido da chave do registro.

*obj*<br/>
fora Referência a uma variável [CObject](../../mfc/reference/cobject-class.md) que recebe o valor lido da chave do registro.

*pObj*<br/>
fora Referência a um ponteiro para uma `CObject` variável que recebe o valor lido da chave do registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Read`verifica *pszKey* como uma subchave de `m_hKey`.

##  <a name="write"></a>  CSettingsStore::Write

Grava um valor no registro na chave aberta.

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
no Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido.

*iVal*<br/>
no Referência a uma variável de inteiro que contém os dados a serem armazenados.

*dwVal*<br/>
no Referência a uma variável de palavra dupla de 32 bits que contém os dados a serem armazenados.

*pszVal*<br/>
no Ponteiro para uma variável de cadeia de caracteres terminada em nulo que contém os dados a serem armazenados.

*scStringList*<br/>
no Referência a uma variável [CStringList](../../mfc/reference/cstringlist-class.md) que contém os dados a serem armazenados.

*bcArray*<br/>
no Referência a uma variável de matriz de bytes que contém os dados a serem armazenados.

*scArray*<br/>
no Referência a uma variável de matriz de cadeia de caracteres que contém os dados a serem armazenados.

*dwcArray*<br/>
no Referência a uma variável de matriz de palavras duplas de 32 bits que contém os dados a serem armazenados.

*wcArray*<br/>
no Referência a uma variável de matriz de palavras de 16 bits que contém os dados a serem armazenados.

*rect*<br/>
no Referência a uma variável [CRect](../../atl-mfc-shared/reference/crect-class.md) que contém os dados a serem armazenados.

*lpPoint*<br/>
no Referência a um ponteiro para uma `POINT` variável que contém os dados a serem armazenados.

*pData*<br/>
no Ponteiro para um buffer que contém os dados a serem armazenados.

*nBytes*<br/>
no Especifica o tamanho, em bytes, dos dados aos quais o parâmetro *pData* aponta.

*list*<br/>
no Referência a uma variável [CObList](../../mfc/reference/coblist-class.md) que contém os dados a serem armazenados.

*obj*<br/>
no Referência a uma variável [CObject](../../mfc/reference/cobject-class.md) que contém os dados a serem armazenados.

*pObj*<br/>
no Ponteiro para um ponteiro para uma `CObject` variável que contém os dados a serem armazenados.

### <a name="return-value"></a>Valor de retorno

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para gravar no registro, você deve definir *bReadOnly* como um valor diferente de zero ao criar um objeto [CSettingsStore](../../mfc/reference/csettingsstore-class.md) . Para obter mais informações, consulte [CSettingsStore:: CSettingsStore](#csettingsstore).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)
