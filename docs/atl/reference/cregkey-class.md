---
title: Classe CRegkey
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
ms.openlocfilehash: d3bdb2e7c3ab0ef56ef7f6fba5d43f1ba0bb7fc6
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81746513"
---
# <a name="cregkey-class"></a>Classe CRegkey

Esta classe fornece métodos para manipular entradas no registro do sistema.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CRegKey
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRegkey::CRegkey](#cregkey)|O construtor.|
|[CRegkey::~CRegkey](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRegkey::anexar](#attach)|Chame este método para anexar `CRegKey` um HKEY ao objeto, definindo a [alça do](#m_hkey) membro m_hKey para `hKey`.|
|[CRegkey::Fechar](#close)|Chame este método para liberar a alça do membro [m_hKey](#m_hkey) e configurá-la como NULL.|
|[CRegkey::Criar](#create)|Chame este método para criar a chave especificada, se `hKeyParent`ela não existir como uma subchave de .|
|[CRegkey::DeleteSubkey](#deletesubkey)|Chame este método para remover a chave especificada do registro.|
|[CRegkey::DeleteValue](#deletevalue)|Chame este método para remover um campo de valor de [m_hKey](#m_hkey).|
|[CRegkey::Detach](#detach)|Chame este método para separar a `CRegKey` alça do `m_hKey` membro [m_hKey](#m_hkey) do objeto e definir como NULA.|
|[CRegkey::Enumkey](#enumkey)|Chame este método para enumerar as subchaves da chave de registro aberto.|
|[CRegkey::Flush](#flush)|Chame este método para escrever todos os atributos da chave de registro aberto no registro.|
|[CRegkey::GetkeySecurity](#getkeysecurity)|Chame este método para recuperar uma cópia do descritor de segurança protegendo a chave de registro aberto.|
|[CRegkey::notificarchangeKeyValue](#notifychangekeyvalue)|Este método notifica o chamador sobre alterações nos atributos ou conteúdo da chave de registro aberto.|
|[CRegkey::Aberto](#open)|Chame este método para abrir a chave especificada e definir [m_hKey](#m_hkey) para a alça desta chave.|
|[CRegkey::QueryBinaryValue](#querybinaryvalue)|Chame este método para recuperar os dados binários para um nome de valor especificado.|
|[CRegKey::QueryDWORDValue](#querydwordvalue)|Chame este método para recuperar os dados do DWORD para um nome de valor especificado.|
|[CRegkey::QueryGUIDValue](#queryguidvalue)|Chame este método para recuperar os dados GUID para um nome de valor especificado.|
|[CRegkey::QueryMultiStringValue](#querymultistringvalue)|Chame este método para recuperar os dados de várias cordas para um nome de valor especificado.|
|[CRegkey::QueryQWORDValue](#queryqwordvalue)|Chame este método para recuperar os dados do QWORD para um nome de valor especificado.|
|[CRegkey::QueryStringValue](#querystringvalue)|Chame este método para recuperar os dados da seqüência para um nome de valor especificado.|
|[CRegkey::QueryValue](#queryvalue)|Chame este método para recuperar os dados para o campo de valor especificado de [m_hKey](#m_hkey). Versões anteriores deste método não são mais suportadas e são marcadas como ATL_DEPRECATED.|
|[CRegkey::RecurseDeleteKey](#recursedeletekey)|Chame este método para remover a chave especificada do registro e remover explicitamente quaisquer subchaves.|
|[CRegkey::SetBinaryValue](#setbinaryvalue)|Chame este método para definir o valor binário da chave de registro.|
|[CRegkey::setDWORDValue](#setdwordvalue)|Chame este método para definir o valor DWORD da chave de registro.|
|[CRegkey::SetGUIDValue](#setguidvalue)|Chame este método para definir o valor GUID da chave de registro.|
|[CRegkey::setkeysecurity](#setkeysecurity)|Chame este método para definir a segurança da chave de registro.|
|[CRegkey::setkeyvalue](#setkeyvalue)|Chame este método para armazenar dados em um campo de valor especificado de uma chave especificada.|
|[CRegkey::setMultistringvalue](#setmultistringvalue)|Chame este método para definir o valor de várias cordas da chave de registro.|
|[CRegkey::SetQWORDValue](#setqwordvalue)|Chame este método para definir o valor QWORD da chave de registro.|
|[CRegkey::setStringValue](#setstringvalue)|Chame este método para definir o valor da seqüência da chave de registro.|
|[CRegkey::setValue](#setvalue)|Chame este método para armazenar dados no campo de valor especificado de [m_hKey](#m_hkey). Versões anteriores deste método não são mais suportadas e são marcadas como ATL_DEPRECATED.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRegkey::operador HKEY](#operator_hkey)|Converte `CRegKey` um objeto em um HKEY.|
|[CRegKey::operador =](#operator_eq)|Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRegkey::m_hKey](#m_hkey)|Contém uma alça da chave `CRegKey` de registro associada ao objeto.|
|[CRegkey::m_pTM](#m_ptm)|Ponteiro `CAtlTransactionManager` para objeto|

## <a name="remarks"></a>Comentários

`CRegKey`fornece métodos para criar e excluir chaves e valores no registro do sistema. O registro contém um conjunto de definições específicas de instalação para componentes do sistema, como números de versão de software, mapeamentos lógico-físicos de hardware instalado e objetos COM.

`CRegKey`fornece uma interface de programação para o registro do sistema para uma determinada máquina. Por exemplo, para abrir uma `CRegKey::Open`chave de registro específica, ligue . Para recuperar ou modificar um `CRegKey::QueryValue` `CRegKey::SetValue`valor de dados, ligue ou, respectivamente. Para fechar uma `CRegKey::Close`chave, ligue.

Quando você fecha uma chave, seus dados de registro são gravados (lavados) no disco rígido. Esse processo pode demorar vários segundos. Se o aplicativo tiver que escrever explicitamente dados de registro no disco rígido, você pode chamar a função [RegFlushKey](/windows/win32/api/winreg/nf-winreg-regflushkey) Win32. No `RegFlushKey` entanto, usa muitos recursos do sistema e deve ser chamado apenas quando absolutamente necessário.

> [!IMPORTANT]
> Todos os métodos que permitem ao chamador especificar um local de registro têm o potencial de ler dados que não são confiáveis. Os métodos que fazem uso do [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) devem levar em consideração que esta função não lida explicitamente com strings que são anuladas por NULL. Ambas as condições devem ser verificadas pelo código de chamada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="cregkeyattach"></a><a name="attach"></a>CRegkey::anexar

Chame este método para anexar `CRegKey` um HKEY ao objeto definindo a alça do membro [m_hKey](#m_hkey) para *hKey*.

```cpp
void Attach(HKEY hKey) throw();
```

### <a name="parameters"></a>Parâmetros

*Hkey*<br/>
A alça de uma chave de registro.

### <a name="remarks"></a>Comentários

`Attach`afirmará `m_hKey` se não for NULA.

## <a name="cregkeyclose"></a><a name="close"></a>CRegkey::Fechar

Chame este método para liberar a alça do membro [m_hKey](#m_hkey) e configurá-la como NULL.

```
LONG Close() throw();
```

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS; caso contrário, retorna um valor de erro.

## <a name="cregkeycreate"></a><a name="create"></a>CRegkey::Criar

Chame este método para criar a chave especificada, se ela não existir como uma subchave de *hKeyParent*.

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
A alça de uma chave aberta.

*lpszKeyName*<br/>
Especifica o nome de uma chave a ser criada ou aberta. Este nome deve ser uma sub-chave de *hKeyParent*.

*lpszClass*<br/>
Especifica a classe da chave a ser criada ou aberta. O valor padrão é REG_NONE.

*dwOptions*<br/>
Opções para a chave. O valor padrão é REG_OPTION_NON_VOLATILE. Para obter uma lista de possíveis valores e descrições, consulte [RegCreateKeyEx](/windows/win32/api/winreg/nf-winreg-regcreatekeyexw) no SDK do Windows.

*samDesired*<br/>
O acesso de segurança para a chave. O valor padrão é KEY_READ KEY_WRITE &#124;. Para obter uma lista de possíveis `RegCreateKeyEx`valores e descrições, consulte .

*lpSecAttr*<br/>
Um ponteiro para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que indica se a alça da chave pode ser herdada por um processo de criança. Por padrão, este parâmetro é NULO (o que significa que a alça não pode ser herdada).

*lpdwDisposition*<br/>
[fora] Se não NULA, recupera REG_CREATED_NEW_KEY (se a chave não existisse e foi criada) ou REG_OPENED_EXISTING_KEY (se a chave existisse e fosse aberta).

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS e abre a chave. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

`Create`define o membro [m_hKey](#m_hkey) para a alça desta chave.

## <a name="cregkeycregkey"></a><a name="cregkey"></a>CRegkey::CRegkey

O construtor.

```
CRegKey() throw();
CRegKey(CRegKey& key) throw();
explicit CRegKey(HKEY hKey) throw();
CRegKey(CAtlTransactionManager* pTM) throw();
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
Uma referência a um objeto `CRegKey`.

*Hkey*<br/>
Uma alça para uma chave de registro.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Cria um novo objeto `CRegKey`. O objeto pode ser criado `CRegKey` a partir de um objeto existente, ou de uma alça para uma chave de registro.

## <a name="cregkeycregkey"></a><a name="dtor"></a>CRegkey::~CRegkey

O destruidor.

```
~CRegKey() throw();
```

### <a name="remarks"></a>Comentários

O destruidor `m_hKey`libera.

## <a name="cregkeydeletesubkey"></a><a name="deletesubkey"></a>CRegkey::DeleteSubkey

Chame este método para remover a chave especificada do registro.

```
LONG DeleteSubKey(LPCTSTR lpszSubKey) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszSubKey*<br/>
Especifica o nome da chave a ser excluída. Este nome deve ser uma subchave de [m_hKey.](#m_hkey)

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

`DeleteSubKey`só pode excluir uma chave que não tem subchaves. Se a chave tiver subchaves, chame [RecurseDeleteKey.](#recursedeletekey)

## <a name="cregkeydeletevalue"></a><a name="deletevalue"></a>CRegkey::DeleteValue

Chame este método para remover um campo de valor de [m_hKey](#m_hkey).

```
LONG DeleteValue(LPCTSTR lpszValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Lpszvalue*<br/>
Especifica o campo de valor a ser removido.

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

## <a name="cregkeydetach"></a><a name="detach"></a>CRegkey::Detach

Chame este método para separar a `CRegKey` alça do `m_hKey` membro [m_hKey](#m_hkey) do objeto e definir como NULA.

```
HKEY Detach() throw();
```

### <a name="return-value"></a>Valor retornado

O HKEY associado `CRegKey` ao objeto.

## <a name="cregkeyenumkey"></a><a name="enumkey"></a>CRegkey::Enumkey

Chame este método para enumerar as subchaves da chave de registro aberto.

```
LONG EnumKey(
    DWORD iIndex,
    LPTSTR pszName,
    LPDWORD pnNameLength,
    FILETIME* pftLastWriteTime = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
O índice de sub-chave. Este parâmetro deve ser zero para a primeira chamada e, em seguida, incrementado para chamadas subseqüentes

*Pszname*<br/>
Ponteiro para um buffer que recebe o nome da subchave, incluindo o caractere nulo de terminação. Apenas o nome da subchave é copiado para o buffer, não para a hierarquia de tecla completa.

*pnNameLength*<br/>
Ponteiro para uma variável que especifica o tamanho, em TCHARs, do buffer especificado pelo parâmetro *pszName.* Este tamanho deve incluir o caráter nulo de terminação. Quando o método retorna, a variável apontada por *pnNameLength* contém o número de caracteres armazenados no buffer. A contagem devolvida não inclui o caráter nulo final.

*pftLastWriteTime*<br/>
Ponteiro para uma variável que recebe o tempo que a subchave enumerada foi escrita pela última vez.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Para enumerar as subchaves, ligue `CRegKey::EnumKey` com um índice de zero. Aumente o valor do índice e repita até que o método retorne ERROR_NO_MORE_ITEMS. Para obter mais informações, consulte [RegEnumKeyEx](/windows/win32/api/winreg/nf-winreg-regenumkeyexw) no SDK do Windows.

## <a name="cregkeyflush"></a><a name="flush"></a>CRegkey::Flush

Chame este método para escrever todos os atributos da chave de registro aberto no registro.

```
LONG Flush() throw();
```

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [RegEnumFlush](/windows/win32/api/winreg/nf-winreg-regflushkey) no Windows SDK.

## <a name="cregkeygetkeysecurity"></a><a name="getkeysecurity"></a>CRegkey::GetkeySecurity

Chame este método para recuperar uma cópia do descritor de segurança protegendo a chave de registro aberto.

```
LONG GetKeySecurity(
    SECURITY_INFORMATION si,
    PSECURITY_DESCRIPTOR psd,
    LPDWORD pnBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*si*<br/>
O [SECURITY_INFORMATION](/windows/win32/SecAuthZ/security-information) valor que indica as informações de segurança solicitadas.

*Psd*<br/>
Um ponteiro para um buffer que recebe uma cópia do descritor de segurança solicitado.

*pnBytes*<br/>
O tamanho, em bytes, do tampão apontado pelo *PSD*.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno é definido como um código de erro não zero no WINERROR. H.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [RegGetKeySecurity](/windows/win32/api/winreg/nf-winreg-reggetkeysecurity).

## <a name="cregkeym_hkey"></a><a name="m_hkey"></a>CRegkey::m_hKey

Contém uma alça da chave `CRegKey` de registro associada ao objeto.

```
HKEY m_hKey;
```

## <a name="cregkeym_ptm"></a><a name="m_ptm"></a>CRegkey::m_pTM

Ponteiro para `CAtlTransactionManager` um objeto.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

## <a name="cregkeynotifychangekeyvalue"></a><a name="notifychangekeyvalue"></a>CRegkey::notificarchangeKeyValue

Este método notifica o chamador sobre alterações nos atributos ou conteúdo da chave de registro aberto.

```
LONG NotifyChangeKeyValue(
    BOOL bWatchSubtree,
    DWORD dwNotifyFilter,
    HANDLE hEvent,
    BOOL bAsync = TRUE) throw();
```

### <a name="parameters"></a>Parâmetros

*bWatchSubtree*<br/>
Especifica um sinalizador que indique se deve relatar alterações na chave especificada e em todas as suas subchaves ou apenas na tecla especificada. Se este parâmetro for TRUE, o método relatará alterações na tecla e nas subchaves. Se o parâmetro for FALSO, o método relata alterações apenas na chave.

*dwNotifyFilter*<br/>
Especifica um conjunto de sinalizadores que controlam quais alterações devem ser relatadas. Este parâmetro pode ser uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|REG_NOTIFY_CHANGE_NAME|Notifique o chamador se uma subchave for adicionada ou excluída.|
|REG_NOTIFY_CHANGE_ATTRIBUTES|Notifique o chamador de alterações nos atributos da chave, como as informações do descritor de segurança.|
|REG_NOTIFY_CHANGE_LAST_SET|Notifique o chamador de alterações para um valor da chave. Isso pode incluir adicionar ou excluir um valor ou alterar um valor existente.|
|REG_NOTIFY_CHANGE_SECURITY|Notifique o chamador de alterações no descritor de segurança da chave.|

*Hevent*<br/>
Manuseie um evento. Se o parâmetro *bAsync* for TRUE, o método retorna imediatamente e as alterações são relatadas sinalizando este evento. Se *bAsync* for FALSE, *hEvent* será ignorado.

*Basync*<br/>
Especifica um sinalizador que indica como o método relata alterações. Se este parâmetro for TRUE, o método retorna imediatamente e relata alterações sinalizando o evento especificado. Quando este parâmetro é FALSO, o método não retorna até que uma alteração tenha ocorrido. Se *hEvent* não especificar um evento válido, o parâmetro *bAsync* não poderá ser VERDADEIRO.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Este método não notificará o chamador se a chave especificada for excluída.

Para obter mais detalhes e um programa de exemplo, consulte [RegNotifyChangeKeyValue](/windows/win32/api/winreg/nf-winreg-regnotifychangekeyvalue).

## <a name="cregkeyopen"></a><a name="open"></a>CRegkey::Aberto

Chame este método para abrir a chave especificada e definir [m_hKey](#m_hkey) para a alça desta chave.

```
LONG Open(
    HKEY hKeyParent,
    LPCTSTR lpszKeyName,
    REGSAM samDesired = KEY_READ | KEY_WRITE) throw();
```

### <a name="parameters"></a>Parâmetros

*hKeyParent*<br/>
A alça de uma chave aberta.

*lpszKeyName*<br/>
Especifica o nome de uma chave a ser criada ou aberta. Este nome deve ser uma sub-chave de *hKeyParent*.

*samDesired*<br/>
O acesso de segurança para a chave. O valor padrão é KEY_ALL_ACCESS. Para obter uma lista de possíveis valores e descrições, consulte [RegCreateKeyEx](/windows/win32/api/winreg/nf-winreg-regcreatekeyexw) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS; caso contrário, um valor de erro não-zero definido em WINERROR. H.

### <a name="remarks"></a>Comentários

Se o parâmetro *lpszKeyName* for NULL ou `Open` apontapara uma string vazia, abrirá uma nova alça da chave identificada por *hKeyParent,* mas não fechará nenhuma alça aberta anteriormente.

Ao contrário [de CRegKey::Create,](#create) `Open` não criará a chave especificada se ela não existir.

## <a name="cregkeyoperator-hkey"></a><a name="operator_hkey"></a>CRegkey::operador HKEY

Converte `CRegKey` um objeto em um HKEY.

```
operator HKEY() const throw();
```

## <a name="cregkeyoperator-"></a><a name="operator_eq"></a>CRegKey::operador =

Operador de atribuição.

```
CRegKey& operator= (CRegKey& key) throw();
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave para copiar.

### <a name="return-value"></a>Valor retornado

Retorna uma referência à nova chave.

### <a name="remarks"></a>Comentários

Este operador desprende *a chave* do objeto `CRegKey` atual e atribui-a ao objeto.

## <a name="cregkeyquerybinaryvalue"></a><a name="querybinaryvalue"></a>CRegkey::QueryBinaryValue

Chame este método para recuperar os dados binários para um nome de valor especificado.

```
LONG QueryBinaryValue(
    LPCTSTR pszValueName,
    void* pValue,
    ULONG* pnBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome do valor para consulta.

*pValue*<br/>
Ponteiro para um buffer que recebe os dados do valor.

*pnBytes*<br/>
Ponteiro para uma variável que especifica o tamanho, em bytes, do buffer apontado pelo parâmetro *pValue.* Quando o método retorna, esta variável contém o tamanho dos dados copiados para o buffer.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ERROR_SUCCESS é devolvido. Se o método não ler um valor, ele retorna um código de erro não zero definido no WINERROR. H. Se os dados referenciados não forem de REG_BINARY tipo, ERROR_INVALID_DATA será devolvido.

### <a name="remarks"></a>Comentários

Este método faz `RegQueryValueEx` uso e confirma que o tipo correto de dados é devolvido. Consulte [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) para obter mais detalhes.

> [!IMPORTANT]
> Este método permite que o chamador especifique qualquer local de registro, potencialmente lendo dados que não são confiáveis. Além disso, a função [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) usada por este método não lida explicitamente com strings que são anuladas por NULL. Ambas as condições devem ser verificadas pelo código de chamada.

## <a name="cregkeyquerydwordvalue"></a><a name="querydwordvalue"></a>CRegKey::QueryDWORDValue

Chame este método para recuperar os dados do DWORD para um nome de valor especificado.

```
LONG QueryDWORDValue(
    LPCTSTR pszValueName,
    DWORD& dwValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome do valor para consulta.

*Dwvalue*<br/>
Ponteiro para um buffer que recebe o DWORD.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ERROR_SUCCESS é devolvido. Se o método não ler um valor, ele retorna um código de erro não zero definido no WINERROR. H. Se os dados referenciados não forem de tipo REG_DWORD, ERROR_INVALID_DATA é devolvido.

### <a name="remarks"></a>Comentários

Este método faz `RegQueryValueEx` uso e confirma que o tipo correto de dados é devolvido. Consulte [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) para obter mais detalhes.

> [!IMPORTANT]
> Este método permite que o chamador especifique qualquer local de registro, potencialmente lendo dados que não são confiáveis. Além disso, a função [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) usada por este método não lida explicitamente com strings que são anuladas por NULL. Ambas as condições devem ser verificadas pelo código de chamada.

## <a name="cregkeyqueryguidvalue"></a><a name="queryguidvalue"></a>CRegkey::QueryGUIDValue

Chame este método para recuperar os dados GUID para um nome de valor especificado.

```
LONG QueryGUIDValue(
    LPCTSTR pszValueName,
    GUID& guidValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome do valor para consulta.

*guidValue*<br/>
Ponteiro para uma variável que recebe o GUID.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ERROR_SUCCESS é devolvido. Se o método não ler um valor, ele retorna um código de erro não zero definido no WINERROR. H. Se os dados referenciados não forem um GUID válido, ERROR_INVALID_DATA será devolvida.

### <a name="remarks"></a>Comentários

Este método faz `CRegKey::QueryStringValue` uso e converte a seqüência em um GUID usando [CLSIDFromString](/windows/win32/api/combaseapi/nf-combaseapi-clsidfromstring).

> [!IMPORTANT]
> Este método permite que o chamador especifique qualquer local de registro, potencialmente lendo dados que não são confiáveis.

## <a name="cregkeyquerymultistringvalue"></a><a name="querymultistringvalue"></a>CRegkey::QueryMultiStringValue

Chame este método para recuperar os dados de várias cordas para um nome de valor especificado.

```
LONG QueryMultiStringValue(
    LPCTSTR pszValueName,
    LPTSTR pszValue,
    ULONG* pnChars) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome do valor para consulta.

*Pszvalue*<br/>
Ponteiro para um buffer que recebe os dados de várias cordas. Uma multistring é uma matriz de seqüências de seqüências terminadas por nulos, terminadas por dois caracteres nulos.

*Pnchars*<br/>
O tamanho, em TCHARs, do buffer apontado pelo *pszValue*. Quando o método retorna, *pnChars* contém o tamanho, em TCHARs, das várias cordas recuperadas, incluindo um caractere nulo terminando.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ERROR_SUCCESS é devolvido. Se o método não ler um valor, ele retorna um código de erro não zero definido no WINERROR. H. Se os dados referenciados não forem de tipo REG_MULTI_SZ, ERROR_INVALID_DATA são devolvidos.

### <a name="remarks"></a>Comentários

Este método faz `RegQueryValueEx` uso e confirma que o tipo correto de dados é devolvido. Consulte [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) para obter mais detalhes.

> [!IMPORTANT]
> Este método permite que o chamador especifique qualquer local de registro, potencialmente lendo dados que não são confiáveis. Além disso, a função [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) usada por este método não lida explicitamente com strings que são anuladas por NULL. Ambas as condições devem ser verificadas pelo código de chamada.

## <a name="cregkeyqueryqwordvalue"></a><a name="queryqwordvalue"></a>CRegkey::QueryQWORDValue

Chame este método para recuperar os dados do QWORD para um nome de valor especificado.

```
LONG QueryQWORDValue(
    LPCTSTR pszValueName,
    ULONGLONG& qwValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome do valor para consulta.

*qwValue*<br/>
Ponteiro para um buffer que recebe o QWORD.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ERROR_SUCCESS é devolvido. Se o método não ler um valor, ele retorna um código de erro não zero definido no WINERROR. H. Se os dados referenciados não forem de REG_QWORD tipo, ERROR_INVALID_DATA são devolvidos.

### <a name="remarks"></a>Comentários

Este método faz `RegQueryValueEx` uso e confirma que o tipo correto de dados é devolvido. Consulte [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) para obter mais detalhes.

> [!IMPORTANT]
> Este método permite que o chamador especifique qualquer local de registro, potencialmente lendo dados que não são confiáveis. Além disso, a função [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) usada por este método não lida explicitamente com strings que são anuladas por NULL. Ambas as condições devem ser verificadas pelo código de chamada.

## <a name="cregkeyquerystringvalue"></a><a name="querystringvalue"></a>CRegkey::QueryStringValue

Chame este método para recuperar os dados da seqüência para um nome de valor especificado.

```
LONG QueryStringValue(
    LPCTSTR pszValueName,
    LPTSTR pszValue,
    ULONG* pnChars) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome do valor para consulta.

*Pszvalue*<br/>
Ponteiro para um buffer que recebe os dados da seqüência.

*Pnchars*<br/>
O tamanho, em TCHARs, do buffer apontado pelo *pszValue*. Quando o método retorna, *pnChars* contém o tamanho, em TCHARs, da seqüência recuperada, incluindo um caractere nulo terminando.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ERROR_SUCCESS é devolvido. Se o método não ler um valor, ele retorna um código de erro não zero definido no WINERROR. H. Se os dados referenciados não forem de tipo REG_SZ, ERROR_INVALID_DATA é devolvido. Se o método retornar ERROR_MORE_DATA, *pnChars* é igual a zero, não o tamanho de buffer necessário em bytes.

### <a name="remarks"></a>Comentários

Este método faz `RegQueryValueEx` uso e confirma que o tipo correto de dados é devolvido. Consulte [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) para obter mais detalhes.

> [!IMPORTANT]
> Este método permite que o chamador especifique qualquer local de registro, potencialmente lendo dados que não são confiáveis. Além disso, a função [RegQueryValueEx](/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) usada por este método não lida explicitamente com strings que são anuladas por NULL. Ambas as condições devem ser verificadas pelo código de chamada.

## <a name="cregkeyqueryvalue"></a><a name="queryvalue"></a>CRegkey::QueryValue

Chame este método para recuperar os dados para o campo de valor especificado de [m_hKey](#m_hkey). Versões anteriores deste método não são mais suportadas e são marcadas como ATL_DEPRECATED.

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

*Pszvaluename*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome do valor para consulta. Se *pszValueName* for NULL ou uma seqüência de string vazia, "", o método recuperará o tipo e os dados para o valor não nomeado ou padrão da chave, se houver.

*pdwType*<br/>
Ponteiro para uma variável que recebe um código indicando o tipo de dados armazenados no valor especificado. O parâmetro *pdwType* pode ser NULO se o código de tipo não for necessário.

*Pdata*<br/>
Ponteiro para um buffer que recebe os dados do valor. Este parâmetro pode ser NULO se os dados não forem necessários.

*pnBytes*<br/>
Ponteiro para uma variável que especifica o tamanho, em bytes, do buffer apontado pelo parâmetro *pData.* Quando o método retorna, esta variável contém o tamanho dos dados copiados para *pData.*

*Dwvalue*<br/>
Os dados numéricos do campo de valor.

*lpszValueName*<br/>
Especifica o campo de valor a ser consultado.

*szValue*<br/>
Os dados de seqüência do campo de valor.

*pdwCount*<br/>
O tamanho dos dados da seqüência. Seu valor é inicialmente definido para o tamanho do buffer *szValue.*

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS; caso contrário, um código de erro não zero definido em WINERROR. H.

### <a name="remarks"></a>Comentários

As duas versões originais não `QueryValue` são mais suportadas e são marcadas como ATL_DEPRECATED. O compilador emitirá um aviso se esses formulários forem usados.

O método restante chama RegQueryValueEx.

> [!IMPORTANT]
> Este método permite que o chamador especifique qualquer local de registro, potencialmente lendo dados que não são confiáveis. Além disso, a função RegQueryValueEx usada por este método não lida explicitamente com strings que são anuladas por NULL. Ambas as condições devem ser verificadas pelo código de chamada.

## <a name="cregkeyrecursedeletekey"></a><a name="recursedeletekey"></a>CRegkey::RecurseDeleteKey

Chame este método para remover a chave especificada do registro e remover explicitamente quaisquer subchaves.

```
LONG RecurseDeleteKey(LPCTSTR lpszKey) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszKey*<br/>
Especifica o nome da chave a ser excluída. Este nome deve ser uma subchave de [m_hKey.](#m_hkey)

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS; caso contrário, um valor de erro não-zero definido em WINERROR. H.

### <a name="remarks"></a>Comentários

Se a chave tiver subchaves, você deve chamar este método para excluir a chave.

## <a name="cregkeysetbinaryvalue"></a><a name="setbinaryvalue"></a>CRegkey::SetBinaryValue

Chame este método para definir o valor binário da chave de registro.

```
LONG SetBinaryValue(
    LPCTSTR pszValueName,
    const void* pValue,
    ULONG nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência contendo o nome do valor a definir. Se um valor com esse nome ainda não estiver presente, o método o adiciona à chave.

*pValue*<br/>
Ponteiro para um buffer contendo os dados a serem armazenados com o nome de valor especificado.

*Nbytes*<br/>
Especifica o tamanho, em bytes, das informações apontadas pelo parâmetro *pValue.*

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Este método usa [o RegSetValueEx](/windows/win32/api/winreg/nf-winreg-regsetvalueexw) para escrever o valor no registro.

## <a name="cregkeysetdwordvalue"></a><a name="setdwordvalue"></a>CRegkey::setDWORDValue

Chame este método para definir o valor DWORD da chave de registro.

```
LONG SetDWORDValue(LPCTSTR pszValueName, DWORD dwValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência contendo o nome do valor a definir. Se um valor com esse nome ainda não estiver presente, o método o adiciona à chave.

*Dwvalue*<br/>
Os dados do DWORD a serem armazenados com o nome de valor especificado.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Este método usa [o RegSetValueEx](/windows/win32/api/winreg/nf-winreg-regsetvalueexw) para escrever o valor no registro.

## <a name="cregkeysetguidvalue"></a><a name="setguidvalue"></a>CRegkey::SetGUIDValue

Chame este método para definir o valor GUID da chave de registro.

```
LONG SetGUIDValue(LPCTSTR pszValueName, REFGUID guidValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência contendo o nome do valor a definir. Se um valor com esse nome ainda não estiver presente, o método o adiciona à chave.

*guidValue*<br/>
Consulte o GUID a ser armazenado com o nome de valor especificado.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Este método faz `CRegKey::SetStringValue` uso e converte o GUID em uma string usando [StringFromGUID2](/windows/win32/api/combaseapi/nf-combaseapi-stringfromguid2).

## <a name="cregkeysetkeyvalue"></a><a name="setkeyvalue"></a>CRegkey::setkeyvalue

Chame este método para armazenar dados em um campo de valor especificado de uma chave especificada.

```
LONG SetKeyValue(
    LPCTSTR lpszKeyName,
    LPCTSTR lpszValue,
    LPCTSTR lpszValueName = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszKeyName*<br/>
Especifica o nome da chave a ser criada ou aberta. Este nome deve ser uma subchave de [m_hKey.](#m_hkey)

*Lpszvalue*<br/>
Especifica os dados a serem armazenados. Este parâmetro deve ser não NULO.

*lpszValueName*<br/>
Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS; caso contrário, um código de erro não zero definido em WINERROR. H.

### <a name="remarks"></a>Comentários

Chame este método para criar ou abrir a tecla *lpszKeyName* e armazenar os dados *lpszValue* no campo de valor *lpszValueName.*

## <a name="cregkeysetkeysecurity"></a><a name="setkeysecurity"></a>CRegkey::setkeysecurity

Chame este método para definir a segurança da chave de registro.

```
LONG SetKeySecurity(SECURITY_INFORMATION si, PSECURITY_DESCRIPTOR psd) throw();
```

### <a name="parameters"></a>Parâmetros

*si*<br/>
Especifica os componentes do descritor de segurança a definir. O valor pode ser uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|DACL_SECURITY_INFORMATION|Define a lista de controle de acesso discricionário da chave (DACL). A chave deve ter acesso WRITE_DAC, ou o processo de chamada deve ser o proprietário do objeto.|
|GROUP_SECURITY_INFORMATION|Define o identificador de segurança de grupo principal (SID) da chave. A chave deve ter acesso WRITE_OWNER, ou o processo de chamada deve ser o proprietário do objeto.|
|OWNER_SECURITY_INFORMATION|Define o SID do proprietário da chave. A chave deve ter acesso WRITE_OWNER, ou o processo de chamada deve ser o proprietário do objeto ou ter o privilégio SE_TAKE_OWNERSHIP_NAME ativado.|
|SACL_SECURITY_INFORMATION|Define a lista de controle de acesso do sistema da chave (SACL). A chave deve ter acesso ACCESS_SYSTEM_SECURITY. A maneira adequada de obter esse acesso é habilitar o [privilégio](/windows/win32/secauthz/privileges) SE_SECURITY_NAME no token de acesso atual do chamador, abrir a alça para ACCESS_SYSTEM_SECURITY acesso e, em seguida, desativar o privilégio.|

*Psd*<br/>
Ponteiro para uma estrutura [de SECURITY_DESCRIPTOR](/windows/win32/api/winnt/ns-winnt-security_descriptor) que especifica os atributos de segurança a definir para a chave especificada.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Define os atributos de segurança da chave. Consulte [RegSetKeySecurity](/windows/win32/api/winreg/nf-winreg-regsetkeysecurity) para obter mais detalhes.

## <a name="cregkeysetmultistringvalue"></a><a name="setmultistringvalue"></a>CRegkey::setMultistringvalue

Chame este método para definir o valor de várias cordas da chave de registro.

```
LONG SetMultiStringValue(LPCTSTR pszValueName, LPCTSTR pszValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência contendo o nome do valor a definir. Se um valor com esse nome ainda não estiver presente, o método o adiciona à chave.

*Pszvalue*<br/>
Ponteiro para os dados de várias cordas a serem armazenados com o nome de valor especificado. Uma multistring é uma matriz de seqüências de seqüências terminadas por nulos, terminadas por dois caracteres nulos.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Este método usa [o RegSetValueEx](/windows/win32/api/winreg/nf-winreg-regsetvalueexw) para escrever o valor no registro.

## <a name="cregkeysetqwordvalue"></a><a name="setqwordvalue"></a>CRegkey::SetQWORDValue

Chame este método para definir o valor QWORD da chave de registro.

```
LONG SetQWORDValue(LPCTSTR pszValueName, ULONGLONG qwValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência contendo o nome do valor a definir. Se um valor com esse nome ainda não estiver presente, o método o adiciona à chave.

*qwValue*<br/>
Os dados do QWORD a serem armazenados com o nome de valor especificado.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Este método usa [o RegSetValueEx](/windows/win32/api/winreg/nf-winreg-regsetvalueexw) para escrever o valor no registro.

## <a name="cregkeysetstringvalue"></a><a name="setstringvalue"></a>CRegkey::setStringValue

Chame este método para definir o valor da seqüência da chave de registro.

```
LONG SetStringValue(
    LPCTSTR pszValueName,
    LPCTSTR pszValue,
    DWORD dwType = REG_SZ) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszvaluename*<br/>
Ponteiro para uma seqüência contendo o nome do valor a definir. Se um valor com esse nome ainda não estiver presente, o método o adiciona à chave.

*Pszvalue*<br/>
Ponteiro para os dados da seqüência a serem armazenados com o nome de valor especificado.

*Dwtype*<br/>
O tipo de string para escrever no registro: REG_SZ (o padrão) ou REG_EXPAND_SZ (para multistrings).

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno será ERROR_SUCCESS. Se o método falhar, o valor de retorno será um código de erro não zero definido no WINERROR. H.

### <a name="remarks"></a>Comentários

Este método usa [o RegSetValueEx](/windows/win32/api/winreg/nf-winreg-regsetvalueexw) para escrever o valor no registro.

## <a name="cregkeysetvalue"></a><a name="setvalue"></a>CRegkey::setValue

Chame este método para armazenar dados no campo de valor especificado de [m_hKey](#m_hkey). Versões anteriores deste método não são mais suportadas e são marcadas como ATL_DEPRECATED.

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

*Pszvaluename*<br/>
Ponteiro para uma seqüência contendo o nome do valor a definir. Se um valor com esse nome ainda não estiver presente na chave, o método o adiciona à chave. Se *pszValueName* for NULL ou uma seqüência de string vazia, "", o método definirá o tipo e os dados para o valor não nomeado ou padrão da chave.

*Dwtype*<br/>
Especifica um código que indica o tipo de dados apontados pelo parâmetro *pValue.*

*pValue*<br/>
Ponteiro para um buffer contendo os dados a serem armazenados com o nome de valor especificado.

*Nbytes*<br/>
Especifica o tamanho, em bytes, das informações apontadas pelo parâmetro *pValue.* Se os dados forem de tipo REG_SZ, REG_EXPAND_SZ ou REG_MULTI_SZ, *os nBytes* devem incluir o tamanho do caractere nulo de terminação.

*hKeyParent*<br/>
A alça de uma chave aberta.

*lpszKeyName*<br/>
Especifica o nome de uma chave a ser criada ou aberta. Este nome deve ser uma sub-chave de *hKeyParent*.

*Lpszvalue*<br/>
Especifica os dados a serem armazenados. Este parâmetro deve ser não NULO.

*lpszValueName*<br/>
Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.

*Dwvalue*<br/>
Especifica os dados a serem armazenados.

*bMulti*<br/>
Se for falso, indica que a seqüência é de tipo REG_SZ. Se for verdade, indica que a seqüência é uma multistring de tipo REG_MULTI_SZ.

*nValueLen*<br/>
Se *bMulti* for verdadeiro, *nValueLen* é o comprimento da seqüência *lpszValue* em caracteres. Se *bMulti* for falso, um valor de -1 indica que o método calculará o comprimento automaticamente.

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna ERROR_SUCCESS; caso contrário, um código de erro não zero definido em WINERROR. H.

### <a name="remarks"></a>Comentários

As duas versões originais `SetValue` estão marcadas como ATL_DEPRECATED e não devem mais ser usadas. O compilador emitirá um aviso se esses formulários forem usados.

O terceiro método chama [RegSetValueEx](/windows/win32/api/winreg/nf-winreg-regsetvalueexw).

## <a name="see-also"></a>Confira também

[Amostra de DCOM](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
