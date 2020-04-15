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
ms.openlocfilehash: b1acf959c371aa23ac55ace7fea9466f0e20813f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318463"
---
# <a name="csettingsstore-class"></a>Classe CSettingsStore

Envolve funções de API do Windows, fornecendo uma interface orientada a objetos que você usa para acessar o registro.

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
|[CSettingsStore::Fechar](#close)|Fecha a chave de registro aberto.|
|[CSettingsStore::CreateKey](#createkey)|Abre a chave especificada ou cria-a se ela não existir.|
|[CSettingsStore::Dchave de elete](#deletekey)|Exclui a chave especificada e todos os seus filhos.|
|[CSettingsStore::DeleteValue](#deletevalue)|Exclui o valor especificado da chave aberta.|
|[CSettingsStore::Abrir](#open)|Abre a chave especificada.|
|[CSettingsStore::Read](#read)|Recupera os dados para um valor-chave especificado.|
|[CSettingsStore::Write](#write)|Escreve um valor no registro sob a tecla aberta.|

## <a name="remarks"></a>Comentários

O membro `CreateKey` funciona `Open` e são muito semelhantes. Se a chave de `CreateKey` `Open` registro já existir e funcionar da mesma forma. No entanto, se a `CreateKey` chave de registro `Open` não existir, criará-a, enquanto que retornará um valor de erro.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar os `CSettingsStore` métodos Open e Read da classe. Este trecho de código faz parte da [amostra de demonstração de ponta da ferramenta](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_ToolTipDemo#1](../../mfc/reference/codesnippet/cpp/csettingsstore-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CSettingsStore`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsettingsstore.h

## <a name="csettingsstoreclose"></a><a name="close"></a>CSettingsStore::Fechar

Fecha a chave de registro aberto.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Por padrão, este método é chamado do destructor da [Classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

## <a name="csettingsstorecreatekey"></a><a name="createkey"></a>CSettingsStore::CreateKey

Abre uma chave de registro ou a cria se ela não existir.

```
virtual BOOL CreateKey(LPCTSTR pszPath);
```

### <a name="parameters"></a>Parâmetros

*Pszpath*<br/>
[em] Especifica o nome de uma chave a ser criada ou aberta.

### <a name="return-value"></a>Valor retornado

0 se for bem sucedido; caso contrário, um valor não zero.

### <a name="remarks"></a>Comentários

`CreateKey`usa `m_hKey` como raiz de consultas de registro. Ele procura *pszPath* como uma `m_hKey`subchave de . Se a chave não `CreateKey` existe, cria-a. Caso contrário, ele abre a chave. `CreateKey`em `m_hKey` seguida, define para a tecla criada ou aberta.

## <a name="csettingsstorecsettingsstore"></a><a name="csettingsstore"></a>CSettingsStore::CSettingsStore

Cria um objeto `CSettngsStore`.

```
CSettingsStore(
    BOOL bAdmin,
    BOOL bReadOnly);
```

### <a name="parameters"></a>Parâmetros

*Badmin*<br/>
[em] Parâmetro booleano que especifica `CSettingsStore` se o objeto está agindo no modo administrador.

*bReadOnly*<br/>
[em] Parâmetro booleano que especifica `CSettingsStore` se o objeto foi criado no modo somente leitura.

### <a name="remarks"></a>Comentários

Se *bAdmin* estiver definido `m_hKey` como TRUE, a variável membro será definida como **HKEY_LOCAL_MACHINE**. Se você definir *bAdmin* como FALSO, `m_hKey` está definido como **HKEY_CURRENT_USER**.

O acesso à segurança depende do parâmetro *bReadOnly.* Se *bReadonly* for FALSE, o acesso de segurança será definido como **KEY_ALL_ACCESS**. Se *bReadyOnly* for TRUE, o acesso à segurança será definido como uma combinação de **KEY_QUERY_VALUE, KEY_NOTIFY** e **KEY_ENUMERATE_SUB_KEYS**. Para obter mais informações sobre acesso à segurança junto com o registro, consulte [Segurança de chave de registro e direitos de acesso](/windows/win32/SysInfo/registry-key-security-and-access-rights).

O destruidor para `CSettingsStore` liberações `m_hKey` automaticamente.

## <a name="csettingsstoredeletekey"></a><a name="deletekey"></a>CSettingsStore::Dchave de elete

Exclui uma chave e todos os seus filhos do registro.

```
virtual BOOL DeleteKey(
    LPCTSTR pszPath,
    BOOL bAdmin = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Pszpath*<br/>
[em] O nome da chave para excluir.

*Badmin*<br/>
[em] Switch que especifica a localização da chave a ser excluída.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método falhará `CSettingsStore` se o objeto estiver no modo somente leitura.

Se o parâmetro *bAdmin* `DeleteKey` for zero, procure a chave para excluir sob **HKEY_CURRENT_USER**. Se *bAdmin* não `DeleteKey` for zero, procure a chave para excluir sob **HKEY_LOCAL_MACHINE**.

## <a name="csettingsstoredeletevalue"></a><a name="deletevalue"></a>CSettingsStore::DeleteValue

Exclui um valor `m_hKey`de .

```
virtual BOOL DeleteValue(LPCTSTR pszValue);
```

### <a name="parameters"></a>Parâmetros

*Pszvalue*<br/>
[em] Especifica o campo de valor a ser removido.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="csettingsstoreopen"></a><a name="open"></a>CSettingsStore::Abrir

Abre uma chave de registro.

```
virtual BOOL Open(LPCTSTR pszPath);
```

### <a name="parameters"></a>Parâmetros

*Pszpath*<br/>
[em] O nome de uma chave de registro.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Depois que este método abre com `m_hKey` sucesso a chave especificada, ele define para o cabo desta chave.

## <a name="csettingsstoreread"></a><a name="read"></a>CSettingsStore::Read

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
[em] Ponteiro para uma seqüência de terminadas nula que contém o nome do valor a ser lido no registro.

*iVal*<br/>
[fora] Referência a uma variável inteiro que recebe o valor lido da chave de registro.

*dwVal*<br/>
[fora] Referência a uma variável de palavras duplas de 32 bits que recebe o valor lido da chave de registro.

*sVal*<br/>
[fora] Referência a uma variável de string que recebe o valor lido da chave de registro.

*scStringList*<br/>
[fora] Referência a uma variável de lista de strings que recebe o valor lido da chave de registro.

*scArray*<br/>
[fora] Referência a uma variável de matriz de strings que recebe o valor lido da chave de registro.

*dwcArray*<br/>
[fora] Consulte uma variável de matriz de palavras duplas de 32 bits que recebe a leitura de valor da chave de registro.

*wcArray*<br/>
[fora] Referência a uma variável de matriz de palavras de 16 bits que recebe a leitura de valor da chave de registro.

*bcArray*<br/>
[fora] Referência a uma variável de matriz de byte que recebe a leitura do valor da chave de registro.

*Lppoint*<br/>
[fora] Referência a um `POINT` ponteiro para uma estrutura que recebe o valor lido da chave de registro.

*Rect*<br/>
[fora] Referência a uma variável [CRect](../../atl-mfc-shared/reference/crect-class.md) que recebe o valor lido da chave de registro.

*Ppdata*<br/>
[fora] Ponteiro para um ponteiro para dados que recebe o valor lido da chave de registro.

*pBytes*<br/>
[fora] Ponteiro para uma variável inteiro não assinada. Esta variável recebe o tamanho do buffer que *ppData* aponta.

*list*<br/>
[fora] Consulte uma variável [CObList](../../mfc/reference/coblist-class.md) que recebe a leitura do valor da chave de registro.

*obj*<br/>
[fora] Referência a uma variável [CObject](../../mfc/reference/cobject-class.md) que recebe o valor lido da chave de registro.

*pObj*<br/>
[fora] Referência a um `CObject` ponteiro para uma variável que recebe o valor lido da chave de registro.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Read`verifica para *pszKey* como `m_hKey`uma subchave de .

## <a name="csettingsstorewrite"></a><a name="write"></a>CSettingsStore::Write

Escreve um valor no registro sob a tecla aberta.

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
[em] Ponteiro para uma seqüência que contém o nome do valor a definir.

*iVal*<br/>
[em] Consulte uma variável inteira que contenha os dados a serem armazenar.

*dwVal*<br/>
[em] Consulte uma variável de palavras duplas de 32 bits que contém os dados a serem armazenar.

*pszVal*<br/>
[em] Pointer para uma variável de seqüência de seqüência sumida que contém os dados a serem armazenar.

*scStringList*<br/>
[em] Consulte uma variável [CStringList](../../mfc/reference/cstringlist-class.md) que contenha os dados a serem armazenar.

*bcArray*<br/>
[em] Consulte uma variável de matriz de byte que contenha os dados a serem armazenar.

*scArray*<br/>
[em] Referência a uma variável string array que contém os dados a serem armazenar.

*dwcArray*<br/>
[em] Consulte uma variável de matriz de palavras duplas de 32 bits que contém os dados a serem armazenar.

*wcArray*<br/>
[em] Referência a uma variável de matriz de palavras de 16 bits que contém os dados a serem armazenar.

*Rect*<br/>
[em] Consulte uma variável [CRect](../../atl-mfc-shared/reference/crect-class.md) que contenha os dados a serem armazenar.

*Lppoint*<br/>
[em] Consulte um ponteiro `POINT` para uma variável que contenha os dados a armazenar.

*Pdata*<br/>
[em] Ponteiro para um buffer que contém os dados a serem armazenar.

*Nbytes*<br/>
[em] Especifica o tamanho, em bytes, dos dados aos quais o parâmetro *pData* aponta.

*list*<br/>
[em] Consulte uma variável [CObList](../../mfc/reference/coblist-class.md) que contenha os dados a serem armazenar.

*obj*<br/>
[em] Consulte uma variável [CObject](../../mfc/reference/cobject-class.md) que contenha os dados a serem armazenar.

*pObj*<br/>
[em] Ponteiro para um `CObject` ponteiro para uma variável que contém os dados a armazenar.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Para escrever no registro, você deve definir *bReadOnly* para um valor não zero quando criar um objeto [CSettingsStore.](../../mfc/reference/csettingsstore-class.md) Para obter mais informações, consulte [CSettingsStore::CSettingsStore](#csettingsstore).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe Cwinappex](../../mfc/reference/cwinappex-class.md)
