---
title: Classe CRegKey
ms.date: 11/04/2016
f1_keywords:
- CRegKey
- ATLBASE/ATL::CRegKey
- ATLBASE/ATL::CRegKey::CRegKey
- ATLBASE/ATL::CRegKey::Attach
- ATLBASE/ATL::CRegKey::Close
- ATLBASE/ATL::CRegKey::Create
- ATLBASE/ATL::CRegKey::DeleteSubKey
- ATLBASE/ATL::CRegKey::DeleteValue
- ATLBASE/ATL::CRegKey::Detach
- ATLBASE/ATL::CRegKey::EnumKey
- ATLBASE/ATL::CRegKey::Flush
- ATLBASE/ATL::CRegKey::GetKeySecurity
- ATLBASE/ATL::CRegKey::NotifyChangeKeyValue
- ATLBASE/ATL::CRegKey::Open
- ATLBASE/ATL::CRegKey::QueryBinaryValue
- ATLBASE/ATL::CRegKey::QueryDWORDValue
- ATLBASE/ATL::CRegKey::QueryGUIDValue
- ATLBASE/ATL::CRegKey::QueryMultiStringValue
- ATLBASE/ATL::CRegKey::QueryQWORDValue
- ATLBASE/ATL::CRegKey::QueryStringValue
- ATLBASE/ATL::CRegKey::QueryValue
- ATLBASE/ATL::CRegKey::RecurseDeleteKey
- ATLBASE/ATL::CRegKey::SetBinaryValue
- ATLBASE/ATL::CRegKey::SetDWORDValue
- ATLBASE/ATL::CRegKey::SetGUIDValue
- ATLBASE/ATL::CRegKey::SetKeySecurity
- ATLBASE/ATL::CRegKey::SetKeyValue
- ATLBASE/ATL::CRegKey::SetMultiStringValue
- ATLBASE/ATL::CRegKey::SetQWORDValue
- ATLBASE/ATL::CRegKey::SetStringValue
- ATLBASE/ATL::CRegKey::SetValue
- ATLBASE/ATL::CRegKey::m_hKey
- ATLBASE/ATL::CRegKey::m_pTM
helpviewer_keywords:
- CRegKey class
- ATL, registry
- registry, deleting values
- registry, writing to
- registry, deleting keys
ms.assetid: 3afce82b-ba2c-4c1a-8404-dc969e1af74b
ms.openlocfilehash: bce5a16dd8d6564b6a0d3fa0344fe5cb2303764f
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915789"
---
# <a name="cregkey-class"></a>Classe CRegKey

Essa classe fornece métodos para manipular entradas no registro do sistema.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CRegKey
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRegKey::CRegKey](#cregkey)|O construtor.|
|[CRegKey::~CRegKey](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRegKey::Attach](#attach)|Chame esse método para anexar um HKEY ao `CRegKey` objeto definindo o identificador de membro [m_hKey](#m_hkey) como. `hKey`|
|[CRegKey::Close](#close)|Chame esse método para liberar o identificador de membro [m_hKey](#m_hkey) e defini-lo como nulo.|
|[CRegKey::Create](#create)|Chame esse método para criar a chave especificada, se ela não existir como uma subchave de `hKeyParent`.|
|[CRegKey::DeleteSubKey](#deletesubkey)|Chame esse método para remover a chave especificada do registro.|
|[CRegKey::DeleteValue](#deletevalue)|Chame esse método para remover um campo de valor de [m_hKey](#m_hkey).|
|[CRegKey::Detach](#detach)|Chame esse método para desanexar o identificador de membro [m_hKey](#m_hkey) do objeto `CRegKey` e definir `m_hKey` como nulo.|
|[CRegKey::EnumKey](#enumkey)|Chame esse método para enumerar as subchaves da chave do registro aberta.|
|[CRegKey::Flush](#flush)|Chame esse método para gravar todos os atributos da chave do registro aberta no registro.|
|[CRegKey::GetKeySecurity](#getkeysecurity)|Chame esse método para recuperar uma cópia do descritor de segurança que protege a chave do registro aberto.|
|[CRegKey::NotifyChangeKeyValue](#notifychangekeyvalue)|Esse método notifica o chamador sobre as alterações nos atributos ou no conteúdo da chave do registro aberto.|
|[CRegKey::Open](#open)|Chame esse método para abrir a chave especificada e defina [m_hKey](#m_hkey) como o identificador dessa chave.|
|[CRegKey::QueryBinaryValue](#querybinaryvalue)|Chame esse método para recuperar os dados binários para um nome de valor especificado.|
|[CRegKey::QueryDWORDValue](#querydwordvalue)|Chame esse método para recuperar os dados DWORD para um nome de valor especificado.|
|[CRegKey::QueryGUIDValue](#queryguidvalue)|Chame esse método para recuperar os dados de GUID para um nome de valor especificado.|
|[CRegKey::QueryMultiStringValue](#querymultistringvalue)|Chame esse método para recuperar os dados de cadeia de caracteres multistring para um nome de valor especificado.|
|[CRegKey::QueryQWORDValue](#queryqwordvalue)|Chame esse método para recuperar os dados QWORD para um nome de valor especificado.|
|[CRegKey::QueryStringValue](#querystringvalue)|Chame esse método para recuperar os dados de cadeia de caracteres para um nome de valor especificado.|
|[CRegKey::QueryValue](#queryvalue)|Chame esse método para recuperar os dados para o campo de valor especificado de [m_hKey](#m_hkey). Não há mais suporte para versões anteriores deste método e elas estão marcadas como ATL_DEPRECATED.|
|[CRegKey::RecurseDeleteKey](#recursedeletekey)|Chame esse método para remover a chave especificada do registro e remover explicitamente quaisquer subchaves.|
|[CRegKey::SetBinaryValue](#setbinaryvalue)|Chame esse método para definir o valor binário da chave do registro.|
|[CRegKey::SetDWORDValue](#setdwordvalue)|Chame esse método para definir o valor DWORD da chave do registro.|
|[CRegKey::SetGUIDValue](#setguidvalue)|Chame esse método para definir o valor de GUID da chave do registro.|
|[CRegKey::SetKeySecurity](#setkeysecurity)|Chame esse método para definir a segurança da chave do registro.|
|[CRegKey::SetKeyValue](#setkeyvalue)|Chame esse método para armazenar dados em um campo de valor especificado de uma chave especificada.|
|[CRegKey::SetMultiStringValue](#setmultistringvalue)|Chame esse método para definir o valor de multistring da chave do registro.|
|[CRegKey::SetQWORDValue](#setqwordvalue)|Chame esse método para definir o valor QWORD da chave do registro.|
|[CRegKey::SetStringValue](#setstringvalue)|Chame esse método para definir o valor da cadeia de caracteres da chave do registro.|
|[CRegKey::SetValue](#setvalue)|Chame esse método para armazenar dados no campo valor especificado de [m_hKey](#m_hkey). Não há mais suporte para versões anteriores deste método e elas estão marcadas como ATL_DEPRECATED.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[HKEY CRegKey:: Operator](#operator_hkey)|Converte um `CRegKey` objeto em um HKEY.|
|[CRegKey::operator =](#operator_eq)|Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRegKey::m_hKey](#m_hkey)|Contém um identificador da chave do registro associada `CRegKey` ao objeto.|
|[CRegKey::m_pTM](#m_ptm)|Ponteiro para `CAtlTransactionManager` objeto|

## <a name="remarks"></a>Comentários

`CRegKey`fornece métodos para criar e excluir chaves e valores no registro do sistema. O registro contém um conjunto específico de definições de instalação para componentes do sistema, como números de versão de software, mapeamentos lógicos para físicos de hardware instalado e objetos COM.

`CRegKey`fornece uma interface de programação para o registro do sistema para um determinado computador. Por exemplo, para abrir uma chave de Registro específica, `CRegKey::Open`chame. Para recuperar ou modificar um valor de dados, `CRegKey::QueryValue` chame `CRegKey::SetValue`ou, respectivamente. Para fechar uma chave, chame `CRegKey::Close`.

Quando você fecha uma chave, seus dados de registro são gravados (liberados) no disco rígido. Esse processo pode levar vários segundos. Se seu aplicativo precisar gravar explicitamente os dados do registro no disco rígido, você poderá chamar a função do Win32 [RegFlushKey](/windows/desktop/api/winreg/nf-winreg-regflushkey) . No entanto, `RegFlushKey` o usa muitos recursos do sistema e deve ser chamado somente quando absolutamente necessário.

> [!IMPORTANT]
>  Todos os métodos que permitem que o chamador especifique um local de registro têm o potencial de ler dados que não podem ser confiáveis. Os métodos que fazem uso de [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) devem levar em consideração que essa função não manipula explicitamente as cadeias de caracteres que são terminadas em nulo. As duas condições devem ser verificadas pelo código de chamada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="attach"></a>  CRegKey::Attach

Chame esse método para anexar um HKEY ao `CRegKey` objeto definindo o identificador de membro [m_hKey](#m_hkey) como *HKEY*.

```
void Attach(HKEY hKey) throw();
```

### <a name="parameters"></a>Parâmetros

*hKey*<br/>
O identificador de uma chave do registro.

### <a name="remarks"></a>Comentários

`Attach`será declarado se `m_hKey` for não nulo.

##  <a name="close"></a>  CRegKey::Close

Chame esse método para liberar o identificador de membro [m_hKey](#m_hkey) e defini-lo como nulo.

```
LONG Close() throw();
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS; caso contrário, retorna um valor de erro.

##  <a name="create"></a>  CRegKey::Create

Chame esse método para criar a chave especificada, caso ela não exista como uma subchave de *hKeyParent*.

```
LONG Create(
    HKEY hKeyParent,
    LPCTSTR lpszKeyName,
    LPTSTR lpszClass = REG_NONE,
    DWORD dwOptions = REG_OPTION_NON_VOLATILE,
    REGSAM samDesired = KEY_READ | KEY_WRITE,
    LPSECURITY_ATTRIBUTES lpSecAttr = NULL,
    LPDWORD lpdwDisposition = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*hKeyParent*<br/>
O identificador de uma chave aberta.

*lpszKeyName*<br/>
Especifica o nome de uma chave a ser criada ou aberta. Esse nome deve ser uma subchave de *hKeyParent*.

*lpszClass*<br/>
Especifica a classe da chave a ser criada ou aberta. O valor padrão é REG_NONE.

*dwOptions*<br/>
Opções para a chave. O valor padrão é REG_OPTION_NON_VOLATILE. Para obter uma lista de possíveis valores e descrições, consulte [RegCreateKeyEx](/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) no SDK do Windows.

*samDesired*<br/>
O acesso de segurança para a chave. O valor padrão é KEY_READ &#124; KEY_WRITE. Para obter uma lista de possíveis valores e descrições, `RegCreateKeyEx`consulte.

*lpSecAttr*<br/>
Um ponteiro para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que indica se o identificador da chave pode ser herdado por um processo filho. Por padrão, esse parâmetro é nulo (o que significa que o identificador não pode ser herdado).

*lpdwDisposition*<br/>
fora Se não for NULL, recupera REG_CREATED_NEW_KEY (se a chave não existia e foi criada) ou REG_OPENED_EXISTING_KEY (se a chave existia e foi aberta).

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS e abrirá a chave. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

`Create`define o membro [m_hKey](#m_hkey) para o identificador dessa chave.

##  <a name="cregkey"></a>  CRegKey::CRegKey

O construtor.

```
CRegKey() throw();
CRegKey(CRegKey& key) throw();
explicit CRegKey(HKEY hKey) throw();
CRegKey(CAtlTransactionManager* pTM) throw();
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
Uma referência a um objeto `CRegKey`.

*hKey*<br/>
Um identificador para uma chave do registro.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Cria um novo objeto `CRegKey`. O objeto pode ser criado a partir de `CRegKey` um objeto existente ou de um identificador para uma chave do registro.

##  <a name="dtor"></a>  CRegKey::~CRegKey

O destruidor.

```
~CRegKey() throw();
```

### <a name="remarks"></a>Comentários

As versões `m_hKey`do destruidor.

##  <a name="deletesubkey"></a>  CRegKey::DeleteSubKey

Chame esse método para remover a chave especificada do registro.

```
LONG DeleteSubKey(LPCTSTR lpszSubKey) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszSubKey*<br/>
Especifica o nome da chave a ser excluída. Esse nome deve ser uma subchave de [m_hKey](#m_hkey).

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

`DeleteSubKey`Só é possível excluir uma chave que não tenha subchaves. Se a chave tiver subchaves, chame [RecurseDeleteKey](#recursedeletekey) em vez disso.

##  <a name="deletevalue"></a>  CRegKey::DeleteValue

Chame esse método para remover um campo de valor de [m_hKey](#m_hkey).

```
LONG DeleteValue(LPCTSTR lpszValue) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszValue*<br/>
Especifica o campo de valor a ser removido.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

##  <a name="detach"></a>  CRegKey::Detach

Chame esse método para desanexar o identificador de membro [m_hKey](#m_hkey) do objeto `CRegKey` e definir `m_hKey` como nulo.

```
HKEY Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

A hKey associada `CRegKey` ao objeto.

##  <a name="enumkey"></a>  CRegKey::EnumKey

Chame esse método para enumerar as subchaves da chave do registro aberta.

```
LONG EnumKey(
    DWORD iIndex,
    LPTSTR pszName,
    LPDWORD pnNameLength,
    FILETIME* pftLastWriteTime = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
O índice da subchave. Esse parâmetro deve ser zero para a primeira chamada e, em seguida, incrementado para chamadas subsequentes

*pszName*<br/>
Ponteiro para um buffer que recebe o nome da subchave, incluindo o caractere nulo de terminação. Somente o nome da subchave é copiado para o buffer, não para a hierarquia de chave completa.

*pnNameLength*<br/>
Ponteiro para uma variável que especifica o tamanho, em TCHARs, do buffer especificado pelo parâmetro *pszName* . Esse tamanho deve incluir o caractere nulo de terminação. Quando o método retorna, a variável apontada por *pnNameLength* contém o número de caracteres armazenados no buffer. A contagem retornada não inclui o caractere nulo de terminação.

*pftLastWriteTime*<br/>
Ponteiro para uma variável que recebe a hora em que a subchave enumerada foi gravada pela última vez.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Para enumerar as subchaves `CRegKey::EnumKey` , chame com um índice de zero. Aumente o valor do índice e repita até que o método retorne ERROR_NO_MORE_ITEMS. Para obter mais informações, consulte [RegEnumKeyEx](/windows/desktop/api/winreg/nf-winreg-regenumkeyexa) no SDK do Windows.

##  <a name="flush"></a>  CRegKey::Flush

Chame esse método para gravar todos os atributos da chave do registro aberta no registro.

```
LONG Flush() throw();
```

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [RegEnumFlush](/windows/desktop/api/winreg/nf-winreg-regflushkey) no SDK do Windows.

##  <a name="getkeysecurity"></a>  CRegKey::GetKeySecurity

Chame esse método para recuperar uma cópia do descritor de segurança que protege a chave do registro aberto.

```
LONG GetKeySecurity(
    SECURITY_INFORMATION si,
    PSECURITY_DESCRIPTOR psd,
    LPDWORD pnBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*si*<br/>
O valor [SECURITY_INFORMATION](/windows/desktop/SecAuthZ/security-information) que indica as informações de segurança solicitadas.

*psd*<br/>
Um ponteiro para um buffer que recebe uma cópia do descritor de segurança solicitado.

*pnBytes*<br/>
O tamanho, em bytes, do buffer apontado por *PSD*.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero será definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [RegGetKeySecurity](/windows/desktop/api/winreg/nf-winreg-reggetkeysecurity).

##  <a name="m_hkey"></a>  CRegKey::m_hKey

Contém um identificador da chave do registro associada `CRegKey` ao objeto.

```
HKEY m_hKey;
```

##  <a name="m_ptm"></a>  CRegKey::m_pTM

Ponteiro para um `CAtlTransactionManager` objeto.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

##  <a name="notifychangekeyvalue"></a>  CRegKey::NotifyChangeKeyValue

Esse método notifica o chamador sobre as alterações nos atributos ou no conteúdo da chave do registro aberto.

```
LONG NotifyChangeKeyValue(
    BOOL bWatchSubtree,
    DWORD dwNotifyFilter,
    HANDLE hEvent,
    BOOL bAsync = TRUE) throw();
```

### <a name="parameters"></a>Parâmetros

*bWatchSubtree*<br/>
Especifica um sinalizador que indica se as alterações devem ser relatadas na chave especificada e todas as suas subchaves ou apenas na chave especificada. Se esse parâmetro for TRUE, o método relatará as alterações na chave e em suas subchaves. Se o parâmetro for FALSE, o método relatará alterações somente na chave.

*dwNotifyFilter*<br/>
Especifica um conjunto de sinalizadores que controlam quais alterações devem ser relatadas. Esse parâmetro pode ser uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|REG_NOTIFY_CHANGE_NAME|Notifique o chamador se uma subchave for adicionada ou excluída.|
|REG_NOTIFY_CHANGE_ATTRIBUTES|Notifique o chamador de alterações para os atributos da chave, como as informações do descritor de segurança.|
|REG_NOTIFY_CHANGE_LAST_SET|Notifique o chamador de alterações para um valor da chave. Isso pode incluir adicionar ou excluir um valor ou alterar um valor existente.|
|REG_NOTIFY_CHANGE_SECURITY|Notifique o chamador de alterações no descritor de segurança da chave.|

*hEvent*<br/>
Identificador para um evento. Se o parâmetro *bAsync* for true, o método retornará imediatamente e as alterações serão relatadas sinalizando esse evento. Se *bAsync* for false, *hEvent* será ignorado.

*bAsync*<br/>
Especifica um sinalizador que indica como o método relata as alterações. Se esse parâmetro for TRUE, o método retornará imediatamente e relatará as alterações sinalizando o evento especificado. Quando esse parâmetro for FALSE, o método não retornará até que ocorra uma alteração. Se *hEvent* não especificar um evento válido, o parâmetro *bAsync* não poderá ser true.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Esse método não notificará o chamador se a chave especificada for excluída.

Para obter mais detalhes e um programa de exemplo, consulte [RegNotifyChangeKeyValue](/windows/desktop/api/winreg/nf-winreg-regnotifychangekeyvalue).

##  <a name="open"></a>  CRegKey::Open

Chame esse método para abrir a chave especificada e defina [m_hKey](#m_hkey) como o identificador dessa chave.

```
LONG Open(
    HKEY hKeyParent,
    LPCTSTR lpszKeyName,
    REGSAM samDesired = KEY_READ | KEY_WRITE) throw();
```

### <a name="parameters"></a>Parâmetros

*hKeyParent*<br/>
O identificador de uma chave aberta.

*lpszKeyName*<br/>
Especifica o nome de uma chave a ser criada ou aberta. Esse nome deve ser uma subchave de *hKeyParent*.

*samDesired*<br/>
O acesso de segurança para a chave. O valor padrão é KEY_ALL_ACCESS. Para obter uma lista de possíveis valores e descrições, consulte [RegCreateKeyEx](/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS; caso contrário, um valor de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Se o parâmetro *lpszKeyName* for nulo ou apontar para uma cadeia de caracteres `Open` vazia, o abrirá um novo identificador da chave identificada por *hKeyParent*, mas não fechará nenhum identificador aberto anteriormente.

Ao contrário de [CRegKey:: Create](#create), `Open` o não criará a chave especificada se ela não existir.

##  <a name="operator_hkey"></a>HKEY CRegKey:: Operator

Converte um `CRegKey` objeto em um HKEY.

```
operator HKEY() const throw();
```

##  <a name="operator_eq"></a>  CRegKey::operator =

Operador de atribuição.

```
CRegKey& operator= (CRegKey& key) throw();
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave a ser copiada.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência à nova chave.

### <a name="remarks"></a>Comentários

Esse operador desanexa a *chave* do seu objeto atual e a atribui ao `CRegKey` objeto em vez disso.

##  <a name="querybinaryvalue"></a>  CRegKey::QueryBinaryValue

Chame esse método para recuperar os dados binários para um nome de valor especificado.

```
LONG QueryBinaryValue(
    LPCTSTR pszValueName,
    void* pValue,
    ULONG* pnBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser consultado.

*pValue*<br/>
Ponteiro para um buffer que recebe os dados do valor.

*pnBytes*<br/>
Ponteiro para uma variável que especifica o tamanho, em bytes, do buffer apontado pelo parâmetro de especifique. Quando o método retorna, essa variável contém o tamanho dos dados copiados para o buffer.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, ERROR_SUCCESS será retornado. Se o método não conseguir ler um valor, ele retornará um código de erro diferente de zero definido no WINERROR. T. Se os dados referenciados não forem do tipo REG_BINARY, ERROR_INVALID_DATA será retornado.

### <a name="remarks"></a>Comentários

Esse método usa `RegQueryValueEx` e confirma que o tipo correto de dados é retornado. Consulte [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) para obter mais detalhes.

> [!IMPORTANT]
>  Esse método permite que o chamador especifique qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, a função [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) usada por esse método não manipula explicitamente as cadeias de caracteres que são terminadas em nulo. As duas condições devem ser verificadas pelo código de chamada.

##  <a name="querydwordvalue"></a>  CRegKey::QueryDWORDValue

Chame esse método para recuperar os dados DWORD para um nome de valor especificado.

```
LONG QueryDWORDValue(
    LPCTSTR pszValueName,
    DWORD& dwValue) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser consultado.

*dwValue*<br/>
Ponteiro para um buffer que recebe o DWORD.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, ERROR_SUCCESS será retornado. Se o método não conseguir ler um valor, ele retornará um código de erro diferente de zero definido no WINERROR. T. Se os dados referenciados não forem do tipo REG_DWORD, ERROR_INVALID_DATA será retornado.

### <a name="remarks"></a>Comentários

Esse método usa `RegQueryValueEx` e confirma que o tipo correto de dados é retornado. Consulte [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) para obter mais detalhes.

> [!IMPORTANT]
>  Esse método permite que o chamador especifique qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, a função [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) usada por esse método não manipula explicitamente as cadeias de caracteres que são terminadas em nulo. As duas condições devem ser verificadas pelo código de chamada.

##  <a name="queryguidvalue"></a>  CRegKey::QueryGUIDValue

Chame esse método para recuperar os dados de GUID para um nome de valor especificado.

```
LONG QueryGUIDValue(
    LPCTSTR pszValueName,
    GUID& guidValue) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser consultado.

*guidValue*<br/>
Ponteiro para uma variável que recebe o GUID.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, ERROR_SUCCESS será retornado. Se o método não conseguir ler um valor, ele retornará um código de erro diferente de zero definido no WINERROR. T. Se os dados referenciados não forem um GUID válido, ERROR_INVALID_DATA será retornado.

### <a name="remarks"></a>Comentários

Esse método usa `CRegKey::QueryStringValue` e converte a cadeia de caracteres em um GUID usando [CLSIDFromString](/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromstring).

> [!IMPORTANT]
>  Esse método permite que o chamador especifique qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis.

##  <a name="querymultistringvalue"></a>  CRegKey::QueryMultiStringValue

Chame esse método para recuperar os dados de cadeia de caracteres multistring para um nome de valor especificado.

```
LONG QueryMultiStringValue(
    LPCTSTR pszValueName,
    LPTSTR pszValue,
    ULONG* pnChars) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser consultado.

*pszValue*<br/>
Ponteiro para um buffer que recebe os dados de cadeia de caracteres multistring. Uma multistring é uma matriz de cadeias de caracteres terminadas em nulo, terminadas por dois caracteres nulos.

*pnChars*<br/>
O tamanho, em TCHARs, do buffer apontado por *pszValue*. Quando o método retorna, *pnChars* contém o tamanho, em TCHARs, da multistring recuperada, incluindo um caractere nulo de terminação.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, ERROR_SUCCESS será retornado. Se o método não conseguir ler um valor, ele retornará um código de erro diferente de zero definido no WINERROR. T. Se os dados referenciados não forem do tipo REG_MULTI_SZ, ERROR_INVALID_DATA será retornado.

### <a name="remarks"></a>Comentários

Esse método usa `RegQueryValueEx` e confirma que o tipo correto de dados é retornado. Consulte [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) para obter mais detalhes.

> [!IMPORTANT]
>  Esse método permite que o chamador especifique qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, a função [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) usada por esse método não manipula explicitamente as cadeias de caracteres que são terminadas em nulo. As duas condições devem ser verificadas pelo código de chamada.

##  <a name="queryqwordvalue"></a>  CRegKey::QueryQWORDValue

Chame esse método para recuperar os dados QWORD para um nome de valor especificado.

```
LONG QueryQWORDValue(
    LPCTSTR pszValueName,
    ULONGLONG& qwValue) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser consultado.

*qwValue*<br/>
Ponteiro para um buffer que recebe o QWORD.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, ERROR_SUCCESS será retornado. Se o método não conseguir ler um valor, ele retornará um código de erro diferente de zero definido no WINERROR. T. Se os dados referenciados não forem do tipo REG_QWORD, ERROR_INVALID_DATA será retornado.

### <a name="remarks"></a>Comentários

Esse método usa `RegQueryValueEx` e confirma que o tipo correto de dados é retornado. Consulte [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) para obter mais detalhes.

> [!IMPORTANT]
>  Esse método permite que o chamador especifique qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, a função [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) usada por esse método não manipula explicitamente as cadeias de caracteres que são terminadas em nulo. As duas condições devem ser verificadas pelo código de chamada.

##  <a name="querystringvalue"></a>  CRegKey::QueryStringValue

Chame esse método para recuperar os dados de cadeia de caracteres para um nome de valor especificado.

```
LONG QueryStringValue(
    LPCTSTR pszValueName,
    LPTSTR pszValue,
    ULONG* pnChars) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser consultado.

*pszValue*<br/>
Ponteiro para um buffer que recebe os dados da cadeia de caracteres.

*pnChars*<br/>
O tamanho, em TCHARs, do buffer apontado por *pszValue*. Quando o método retorna, *pnChars* contém o tamanho, em TCHARs, da cadeia de caracteres recuperada, incluindo um caractere nulo de terminação.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, ERROR_SUCCESS será retornado. Se o método não conseguir ler um valor, ele retornará um código de erro diferente de zero definido no WINERROR. T. Se os dados referenciados não forem do tipo REG_SZ, ERROR_INVALID_DATA será retornado. Se o método retornar ERROR_MORE_DATA, *pnChars* será igual a zero, não o tamanho de buffer necessário em bytes.

### <a name="remarks"></a>Comentários

Esse método usa `RegQueryValueEx` e confirma que o tipo correto de dados é retornado. Consulte [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) para obter mais detalhes.

> [!IMPORTANT]
>  Esse método permite que o chamador especifique qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, a função [RegQueryValueEx](/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) usada por esse método não manipula explicitamente as cadeias de caracteres que são terminadas em nulo. As duas condições devem ser verificadas pelo código de chamada.

##  <a name="queryvalue"></a>  CRegKey::QueryValue

Chame esse método para recuperar os dados para o campo de valor especificado de [m_hKey](#m_hkey). Não há mais suporte para versões anteriores deste método e elas estão marcadas como ATL_DEPRECATED.

```
LONG QueryValue(
    LPCTSTR pszValueName,
    DWORD* pdwType,
    void* pData,
    ULONG* pnBytes) throw();

ATL_DEPRECATED LONG QueryValue(
    DWORD& dwValue,
    LPCTSTR lpszValueName);

ATL_DEPRECATED LONG QueryValue(
    LPTSTR szValue,
    LPCTSTR lpszValueName,
    DWORD* pdwCount);
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor a ser consultado. Se *pszValueName* for nulo ou uma cadeia de caracteres vazia, "", o método recuperará o tipo e os dados para o valor padrão ou sem nome de chave, se houver.

*pdwType*<br/>
Ponteiro para uma variável que recebe um código que indica o tipo de dados armazenados no valor especificado. O parâmetro *pdwType* poderá ser nulo se o código de tipo não for necessário.

*pData*<br/>
Ponteiro para um buffer que recebe os dados do valor. Esse parâmetro poderá ser nulo se os dados não forem necessários.

*pnBytes*<br/>
Ponteiro para uma variável que especifica o tamanho, em bytes, do buffer apontado pelo parâmetro *pData* . Quando o método retorna, essa variável contém o tamanho dos dados copiados para *pData.*

*dwValue*<br/>
Os dados numéricos do campo de valor.

*lpszValueName*<br/>
Especifica o campo de valor a ser consultado.

*szValue*<br/>
Os dados de cadeia de caracteres do campo de valor.

*pdwCount*<br/>
O tamanho dos dados da cadeia de caracteres. Seu valor é inicialmente definido como o tamanho do buffer *szValue* .

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS; caso contrário, um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

As duas versões originais do `QueryValue` não são mais suportadas e estão marcadas como ATL_DEPRECATED. O compilador emitirá um aviso se esses formulários forem usados.

O método restante chama RegQueryValueEx.

> [!IMPORTANT]
>  Esse método permite que o chamador especifique qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, a função RegQueryValueEx usada por esse método não manipula explicitamente as cadeias de caracteres que são terminadas em nulo. As duas condições devem ser verificadas pelo código de chamada.

##  <a name="recursedeletekey"></a>  CRegKey::RecurseDeleteKey

Chame esse método para remover a chave especificada do registro e remover explicitamente quaisquer subchaves.

```
LONG RecurseDeleteKey(LPCTSTR lpszKey) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszKey*<br/>
Especifica o nome da chave a ser excluída. Esse nome deve ser uma subchave de [m_hKey](#m_hkey).

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS; caso contrário, um valor de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Se a chave tiver subchaves, você deverá chamar esse método para excluir a chave.

##  <a name="setbinaryvalue"></a>  CRegKey::SetBinaryValue

Chame esse método para definir o valor binário da chave do registro.

```
LONG SetBinaryValue(
    LPCTSTR pszValueName,
    const void* pValue,
    ULONG nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com esse nome ainda não estiver presente, o método o adicionará à chave.

*pValue*<br/>
Ponteiro para um buffer que contém os dados a serem armazenados com o nome de valor especificado.

*nBytes*<br/>
Especifica o tamanho, em bytes, das informações apontadas pelo parâmetro to .

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Esse método usa [RegSetValueEx](/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) para gravar o valor no registro.

##  <a name="setdwordvalue"></a>  CRegKey::SetDWORDValue

Chame esse método para definir o valor DWORD da chave do registro.

```
LONG SetDWORDValue(LPCTSTR pszValueName, DWORD dwValue) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com esse nome ainda não estiver presente, o método o adicionará à chave.

*dwValue*<br/>
Os dados DWORD a serem armazenados com o nome de valor especificado.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Esse método usa [RegSetValueEx](/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) para gravar o valor no registro.

##  <a name="setguidvalue"></a>  CRegKey::SetGUIDValue

Chame esse método para definir o valor de GUID da chave do registro.

```
LONG SetGUIDValue(LPCTSTR pszValueName, REFGUID guidValue) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com esse nome ainda não estiver presente, o método o adicionará à chave.

*guidValue*<br/>
Referência ao GUID a ser armazenado com o nome de valor especificado.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Esse método usa `CRegKey::SetStringValue` e converte o GUID em uma cadeia de caracteres usando [StringFromGUID2](/windows/desktop/api/combaseapi/nf-combaseapi-stringfromguid2).

##  <a name="setkeyvalue"></a>  CRegKey::SetKeyValue

Chame esse método para armazenar dados em um campo de valor especificado de uma chave especificada.

```
LONG SetKeyValue(
    LPCTSTR lpszKeyName,
    LPCTSTR lpszValue,
    LPCTSTR lpszValueName = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszKeyName*<br/>
Especifica o nome da chave a ser criada ou aberta. Esse nome deve ser uma subchave de [m_hKey](#m_hkey).

*lpszValue*<br/>
Especifica os dados a serem armazenados. Esse parâmetro deve ser não nulo.

*lpszValueName*<br/>
Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS; caso contrário, um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Chame esse método para criar ou abrir a chave *lpszKeyName* e armazenar os dados de *lpszValue* no campo valor *lpszValueName* .

##  <a name="setkeysecurity"></a>  CRegKey::SetKeySecurity

Chame esse método para definir a segurança da chave do registro.

```
LONG SetKeySecurity(SECURITY_INFORMATION si, PSECURITY_DESCRIPTOR psd) throw();
```

### <a name="parameters"></a>Parâmetros

*si*<br/>
Especifica os componentes do descritor de segurança a serem definidos. O valor pode ser uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|DACL_SECURITY_INFORMATION|Define a DACL (lista de controle de acesso discricionário) da chave. A chave deve ter acesso WRITE_DAC ou o processo de chamada deve ser o proprietário do objeto.|
|GROUP_SECURITY_INFORMATION|Define o SID (identificador de segurança) do grupo primário da chave. A chave deve ter acesso WRITE_OWNER ou o processo de chamada deve ser o proprietário do objeto.|
|OWNER_SECURITY_INFORMATION|Define o SID do proprietário da chave. A chave deve ter acesso WRITE_OWNER ou o processo de chamada deve ser o proprietário do objeto ou ter o privilégio SE_TAKE_OWNERSHIP_NAME habilitado.|
|SACL_SECURITY_INFORMATION|Define a SACL (lista de controle de acesso do sistema) da chave. A chave deve ter acesso ACCESS_SYSTEM_SECURITY. A maneira correta de obter esse acesso é habilitar o [privilégio](/windows/desktop/secauthz/privileges) SE_SECURITY_NAME no token de acesso atual do chamador, abrir o identificador para acesso ao ACCESS_SYSTEM_SECURITY e, em seguida, desabilitar o privilégio.|

*psd*<br/>
Ponteiro para uma estrutura [SECURITY_DESCRIPTOR](/windows/desktop/api/winnt/ns-winnt-security_descriptor) que especifica os atributos de segurança a serem definidos para a chave especificada.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Define os atributos de segurança da chave. Consulte [RegSetKeySecurity](/windows/desktop/api/winreg/nf-winreg-regsetkeysecurity) para obter mais detalhes.

##  <a name="setmultistringvalue"></a>  CRegKey::SetMultiStringValue

Chame esse método para definir o valor de multistring da chave do registro.

```
LONG SetMultiStringValue(LPCTSTR pszValueName, LPCTSTR pszValue) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com esse nome ainda não estiver presente, o método o adicionará à chave.

*pszValue*<br/>
Ponteiro para os dados multistring a serem armazenados com o nome de valor especificado. Uma multistring é uma matriz de cadeias de caracteres terminadas em nulo, terminadas por dois caracteres nulos.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Esse método usa [RegSetValueEx](/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) para gravar o valor no registro.

##  <a name="setqwordvalue"></a>  CRegKey::SetQWORDValue

Chame esse método para definir o valor QWORD da chave do registro.

```
LONG SetQWORDValue(LPCTSTR pszValueName, ULONGLONG qwValue) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com esse nome ainda não estiver presente, o método o adicionará à chave.

*qwValue*<br/>
Os dados QWORD a serem armazenados com o nome de valor especificado.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Esse método usa [RegSetValueEx](/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) para gravar o valor no registro.

##  <a name="setstringvalue"></a>  CRegKey::SetStringValue

Chame esse método para definir o valor da cadeia de caracteres da chave do registro.

```
LONG SetStringValue(
    LPCTSTR pszValueName,
    LPCTSTR pszValue,
    DWORD dwType = REG_SZ) throw();
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com esse nome ainda não estiver presente, o método o adicionará à chave.

*pszValue*<br/>
Ponteiro para os dados de cadeia de caracteres a serem armazenados com o nome de valor especificado.

*dwType*<br/>
O tipo da cadeia de caracteres a ser gravada no registro: REG_SZ (o padrão) ou REG_EXPAND_SZ (para cadeias de caracteres).

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

Esse método usa [RegSetValueEx](/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) para gravar o valor no registro.

##  <a name="setvalue"></a>  CRegKey::SetValue

Chame esse método para armazenar dados no campo valor especificado de [m_hKey](#m_hkey). Não há mais suporte para versões anteriores deste método e elas estão marcadas como ATL_DEPRECATED.

```
LONG SetValue(
    LPCTSTR pszValueName,
    DWORD dwType,
    const void* pValue,
    ULONG nBytes) throw();

static LONG WINAPI SetValue(
    HKEY hKeyParent,
    LPCTSTR lpszKeyName,
    LPCTSTR lpszValue,
    LPCTSTR lpszValueName = NULL);

ATL_DEPRECATED LONG SetValue(
    DWORD dwValue,
    LPCTSTR lpszValueName);

ATL_DEPRECATED LONG SetValue(
    LPCTSTR lpszValue,
    LPCTSTR lpszValueName = NULL,
    bool bMulti = false,
    int nValueLen = -1);
```

### <a name="parameters"></a>Parâmetros

*pszValueName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com esse nome ainda não estiver presente na chave, o método o adicionará à chave. Se *pszValueName* for nulo ou uma cadeia de caracteres vazia, "", o método definirá o tipo e os dados para o valor padrão ou não nomeado da chave.

*dwType*<br/>
Especifica um código que indica o tipo de dados apontado pelo parâmetro to.

*pValue*<br/>
Ponteiro para um buffer que contém os dados a serem armazenados com o nome de valor especificado.

*nBytes*<br/>
Especifica o tamanho, em bytes, das informações apontadas pelo parâmetro to . Se os dados forem do tipo REG_SZ, REG_EXPAND_SZ ou REG_MULTI_SZ, *nbytes* deverá incluir o tamanho do caractere nulo de terminação.

*hKeyParent*<br/>
O identificador de uma chave aberta.

*lpszKeyName*<br/>
Especifica o nome de uma chave a ser criada ou aberta. Esse nome deve ser uma subchave de *hKeyParent*.

*lpszValue*<br/>
Especifica os dados a serem armazenados. Esse parâmetro deve ser não nulo.

*lpszValueName*<br/>
Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.

*dwValue*<br/>
Especifica os dados a serem armazenados.

*bMulti*<br/>
Se for false, indicará que a cadeia de caracteres é do tipo REG_SZ. Se for true, indicará que a cadeia de caracteres é multistring do tipo REG_MULTI_SZ.

*nValueLen*<br/>
Se *bMulti* for true, *nValueLen* será o comprimento da cadeia de caracteres *lpszValue* em caracteres. Se *bMulti* for false, um valor de-1 indicará que o método calculará o comprimento automaticamente.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará ERROR_SUCCESS; caso contrário, um código de erro diferente de zero definido no WINERROR. T.

### <a name="remarks"></a>Comentários

As duas versões originais do `SetValue` são marcadas como ATL_DEPRECATED e não devem mais ser usadas. O compilador emitirá um aviso se esses formulários forem usados.

O terceiro método chama [RegSetValueEx](/windows/desktop/api/winreg/nf-winreg-regsetvalueexa).

## <a name="see-also"></a>Consulte também

[Exemplo de DCOM](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
