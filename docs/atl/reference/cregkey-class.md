---
title: Classe CRegKey | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs: C++
helpviewer_keywords:
- CRegKey class
- ATL, registry
- registry, deleting values
- registry, writing to
- registry, deleting keys
ms.assetid: 3afce82b-ba2c-4c1a-8404-dc969e1af74b
caps.latest.revision: "25"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: dffc650c54c4a50fb4b3b1fe2c22ac82501b8b45
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cregkey-class"></a>Classe CRegKey
Essa classe fornece métodos para manipular as entradas no registro do sistema.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CRegKey
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRegKey::CRegKey](#cregkey)|O construtor.|  
|[CRegKey:: ~ CRegKey](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRegKey::Attach](#attach)|Chame esse método para anexar um HKEY para o `CRegKey` objeto definindo o [m_hKey](#m_hkey) identificador de membro para `hKey`.|  
|[CRegKey::Close](#close)|Chame este método para liberar o [m_hKey](#m_hkey) membro manipular e defina-o como NULL.|  
|[CRegKey::Create](#create)|Chame esse método para criar a chave especificada, se não existir como uma subchave de `hKeyParent`.|  
|[CRegKey::DeleteSubKey](#deletesubkey)|Chame esse método para remover a chave especificada do registro.|  
|[CRegKey::DeleteValue](#deletevalue)|Chame esse método para remover um campo de valor de [m_hKey](#m_hkey).|  
|[CRegKey::Detach](#detach)|Chame este método para desanexar o [m_hKey](#m_hkey) identificador de membro do `CRegKey` do objeto e defina `m_hKey` como NULL.|  
|[CRegKey::EnumKey](#enumkey)|Chame esse método para enumerar as subchaves da chave do Registro aberta.|  
|[CRegKey::Flush](#flush)|Chame esse método para gravar todos os atributos da chave do Registro aberta no registro.|  
|[CRegKey::GetKeySecurity](#getkeysecurity)|Chame esse método para recuperar uma cópia do descritor de segurança que protege a chave do Registro aberta.|  
|[CRegKey::NotifyChangeKeyValue](#notifychangekeyvalue)|Este método notifica o chamador sobre alterações para os atributos ou conteúdo da chave do Registro aberta.|  
|[CRegKey::Open](#open)|Chame este método para abrir a chave especificada e definir [m_hKey](#m_hkey) no identificador dessa chave.|  
|[CRegKey::QueryBinaryValue](#querybinaryvalue)|Chame este método para recuperar os dados binários para um nome de valor especificado.|  
|[CRegKey::QueryDWORDValue](#querydwordvalue)|Chame este método para recuperar os dados DWORD para um nome de valor especificado.|  
|[CRegKey::QueryGUIDValue](#queryguidvalue)|Chame esse método para recuperar os dados GUID para o nome do valor especificado.|  
|[CRegKey::QueryMultiStringValue](#querymultistringvalue)|Chame este método para recuperar os dados de cadeias de caracteres múltiplas para um nome de valor especificado.|  
|[CRegKey::QueryQWORDValue](#queryqwordvalue)|Chame este método para recuperar os dados QWORD para um nome de valor especificado.|  
|[CRegKey::QueryStringValue](#querystringvalue)|Chame este método para recuperar os dados de cadeia de caracteres para um nome de valor especificado.|  
|[CRegKey::QueryValue](#queryvalue)|Chame esse método para recuperar os dados para o campo de valor especificado de [m_hKey](#m_hkey). Versões anteriores deste método não têm mais suporte e são marcadas como **ATL_DEPRECATED**.|  
|[CRegKey::RecurseDeleteKey](#recursedeletekey)|Chame esse método para remover a chave especificada do registro e remover explicitamente todas as subchaves.|  
|[CRegKey::SetBinaryValue](#setbinaryvalue)|Chame este método para definir o valor binário da chave do registro.|  
|[CRegKey::SetDWORDValue](#setdwordvalue)|Chame este método para definir o valor DWORD da chave do registro.|  
|[CRegKey::SetGUIDValue](#setguidvalue)|Chame este método para definir o valor GUID da chave do registro.|  
|[CRegKey::SetKeySecurity](#setkeysecurity)|Chame esse método para definir a segurança da chave do registro.|  
|[CRegKey::SetKeyValue](#setkeyvalue)|Chame esse método para armazenar dados em um campo de valor especificado de uma chave especificada.|  
|[CRegKey::SetMultiStringValue](#setmultistringvalue)|Chame este método para definir um valor de chave de registro.|  
|[CRegKey::SetQWORDValue](#setqwordvalue)|Chame este método para definir o valor QWORD da chave do registro.|  
|[CRegKey::SetStringValue](#setstringvalue)|Chame este método para definir o valor de cadeia de caracteres da chave do registro.|  
|[CRegKey::SetValue](#setvalue)|Chame esse método para armazenar dados no campo de valor especificado de [m_hKey](#m_hkey). Versões anteriores deste método não têm mais suporte e são marcadas como **ATL_DEPRECATED**.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRegKey::operator HKEY](#operator_hkey)|Converte um `CRegKey` objeto para um HKEY.|  
|[CRegKey::operator =](#operator_eq)|Operador de atribuição.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRegKey::m_hKey](#m_hkey)|Contém um identificador da chave do registro associada a `CRegKey` objeto.|  
|[CRegKey::m_pTM](#m_ptm)|Ponteiro para `CAtlTransactionManager` objeto|  
  
## <a name="remarks"></a>Comentários  
 `CRegKey`fornece métodos para criar e excluir chaves e valores no registro do sistema. O registro contém um conjunto de instalação específicas de definições de componentes do sistema, como números de versão de software, lógico físico mapeamentos de hardware instalado e objetos COM.  
  
 `CRegKey`Fornece uma interface de programação para o registro do sistema para um determinado computador. Por exemplo, para abrir uma chave do registro específica, chamada `CRegKey::Open`. Para recuperar ou modificar um valor de dados, chame `CRegKey::QueryValue` ou `CRegKey::SetValue`, respectivamente. Para fechar uma chave, chame `CRegKey::Close`.  
  
 Quando você fechar uma chave, seus dados de registro são gravados (liberados) para o disco rígido. Esse processo pode levar vários segundos. Se seu aplicativo explicitamente deve gravar os dados do registro para o disco rígido, você pode chamar o [RegFlushKey](http://msdn.microsoft.com/library/windows/desktop/ms724867) função Win32. No entanto, **RegFlushKey** usa muitos recursos do sistema e deve ser chamado apenas quando absolutamente necessário.  
  
> [!IMPORTANT]
>  Todos os métodos que permitem que o chamador especificar um local do Registro têm o potencial para ler dados que não são confiáveis. Métodos que fazem usam de [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) devem levar em consideração que essa função não processa explicitamente as cadeias de caracteres que são terminada nula. Ambas as condições devem ser verificadas para o código de chamada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="attach"></a>CRegKey::Attach  
 Chame esse método para anexar um HKEY para o `CRegKey` objeto definindo o [m_hKey](#m_hkey) identificador de membro para `hKey`.  
  
```
void Attach(HKEY hKey) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hKey`  
 O identificador de uma chave do registro.  
  
### <a name="remarks"></a>Comentários  
 **Anexar** declarará se `m_hKey` não for nulo.  
  
##  <a name="close"></a>CRegKey::Close  
 Chame este método para liberar o [m_hKey](#m_hkey) membro manipular e defina-o como NULL.  
  
```
LONG Close() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará ERROR_SUCCESS; Caso contrário, retorna um valor de erro.  
  
##  <a name="create"></a>CRegKey::Create  
 Chame esse método para criar a chave especificada, se não existir como uma subchave de `hKeyParent`.  
  
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
 `hKeyParent`  
 O identificador de uma chave aberta.  
  
 `lpszKeyName`  
 Especifica o nome de uma chave a ser criado ou aberto. Esse nome deve ser uma subchave de `hKeyParent`.  
  
 `lpszClass`  
 Especifica a classe da chave a ser criado ou aberto. O valor padrão é REG_NONE.  
  
 `dwOptions`  
 Opções para a chave. O valor padrão é REG_OPTION_NON_VOLATILE. Para obter uma lista de possíveis valores e descrições, consulte [RegCreateKeyEx](http://msdn.microsoft.com/library/windows/desktop/ms724844) no SDK do Windows.  
  
 `samDesired`  
 O acesso de segurança para a chave. O valor padrão é KEY_READ &#124; KEY_WRITE. Para obter uma lista de possíveis valores e descrições, consulte **RegCreateKeyEx**.  
  
 *lpSecAttr*  
 Um ponteiro para um [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que indica se o identificador da chave pode ser herdado por um processo filho. Por padrão, esse parâmetro é NULL (o que significa que o identificador não pode ser herdado).  
  
 *lpdwDisposition*  
 [out] Se não nulo, recupera REG_CREATED_NEW_KEY (se a chave não existia e foi criada) ou REG_OPENED_EXISTING_KEY (se a chave existia e foi aberta).  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retorna ERROR_SUCCESS e abre a chave. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 **Criar** define o [m_hKey](#m_hkey) membro para o identificador dessa chave.  
  
##  <a name="cregkey"></a>CRegKey::CRegKey  
 O construtor.  
  
```
CRegKey() throw();
CRegKey(CRegKey& key) throw();
explicit CRegKey(HKEY hKey) throw();
CRegKey(CAtlTransactionManager* pTM) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Uma referência a um objeto `CRegKey`.  
  
 `hKey`  
 Um identificador para uma chave do registro.  
  
 `pTM`  
 Ponteiro para objeto CAtlTransactionManager  
  
### <a name="remarks"></a>Comentários  
 Cria um novo objeto `CRegKey`. O objeto pode ser criado de uma já existente `CRegKey` objeto, ou de um identificador para uma chave do registro.  
  
##  <a name="dtor"></a>CRegKey:: ~ CRegKey  
 O destruidor.  
  
```
~CRegKey() throw();
```  
  
### <a name="remarks"></a>Comentários  
 As versões do destruidor `m_hKey`.  
  
##  <a name="deletesubkey"></a>CRegKey::DeleteSubKey  
 Chame esse método para remover a chave especificada do registro.  
  
```
LONG DeleteSubKey(LPCTSTR lpszSubKey) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSubKey`  
 Especifica o nome da chave para excluir. Esse nome deve ser uma subchave de [m_hKey](#m_hkey).  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 `DeleteSubKey`só pode excluir uma chave que não possuir subchaves. Se a chave tem subchaves, chame [RecurseDeleteKey](#recursedeletekey) em vez disso.  
  
##  <a name="deletevalue"></a>CRegKey::DeleteValue  
 Chame esse método para remover um campo de valor de [m_hKey](#m_hkey).  
  
```
LONG DeleteValue(LPCTSTR lpszValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszValue`  
 Especifica o campo de valor a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
##  <a name="detach"></a>CRegKey::Detach  
 Chame este método para desanexar o [m_hKey](#m_hkey) identificador de membro do `CRegKey` do objeto e defina `m_hKey` como NULL.  
  
```
HKEY Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O HKEY associado a `CRegKey` objeto.  
  
##  <a name="enumkey"></a>CRegKey::EnumKey  
 Chame esse método para enumerar as subchaves da chave do Registro aberta.  
  
```
LONG EnumKey(  
    DWORD iIndex,
    LPTSTR pszName,
    LPDWORD pnNameLength,
    FILETIME* pftLastWriteTime = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `iIndex`  
 O índice subchave. Esse parâmetro deve ser zero para a primeira chamada e, em seguida, incrementados para chamadas subsequentes  
  
 `pszName`  
 Ponteiro para um buffer que recebe o nome da subchave, incluindo o caractere null de terminação. Somente o nome da subchave é copiado para o buffer, não a hierarquia de chave completo.  
  
 *pnNameLength*  
 Ponteiro para uma variável que especifica o tamanho, em TCHARs, do buffer especificado pelo `pszName` parâmetro. Esse tamanho deve incluir o caractere null de terminação. Quando o método retornar, a variável apontada pelo *pnNameLength* contém o número de caracteres armazenados em buffer. A contagem retornada não inclui o caractere null de terminação.  
  
 *pftLastWriteTime*  
 Ponteiro para uma variável que recebe o tempo a subchave enumerada foi gravada pela última.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Para enumerar as subchaves, chame `CRegKey::EnumKey` com um índice de zero. Incrementar o valor de índice e repita até que o método retorne ERROR_NO_MORE_ITEMS. Para obter mais informações, consulte [RegEnumKeyEx](http://msdn.microsoft.com/library/windows/desktop/ms724862) no SDK do Windows.  
  
##  <a name="flush"></a>CRegKey::Flush  
 Chame esse método para gravar todos os atributos da chave do Registro aberta no registro.  
  
```
LONG Flush() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [RegEnumFlush](http://msdn.microsoft.com/library/windows/desktop/ms724867) no SDK do Windows.  
  
##  <a name="getkeysecurity"></a>CRegKey::GetKeySecurity  
 Chame esse método para recuperar uma cópia do descritor de segurança que protege a chave do Registro aberta.  
  
```
LONG GetKeySecurity(  
    SECURITY_INFORMATION si,
    PSECURITY_DESCRIPTOR psd,
    LPDWORD pnBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `si`  
 O [SECURITY_INFORMATION](http://msdn.microsoft.com/library/windows/desktop/aa379573) valor que indica as informações de segurança solicitado.  
  
 `psd`  
 Um ponteiro para um buffer que recebe uma cópia do descritor de segurança solicitado.  
  
 `pnBytes`  
 O tamanho, em bytes, do buffer apontado pelo `psd`.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é que um código de erro diferente de zero é definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [RegGetKeySecurity](http://msdn.microsoft.com/library/windows/desktop/aa379313).  
  
##  <a name="m_hkey"></a>CRegKey::m_hKey  
 Contém um identificador da chave do registro associada a `CRegKey` objeto.  
  
```
HKEY m_hKey;
```  
  
##  <a name="m_ptm"></a>CRegKey::m_pTM  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
```
CAtlTransactionManager* m_pTM;
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="notifychangekeyvalue"></a>CRegKey::NotifyChangeKeyValue  
 Este método notifica o chamador sobre alterações para os atributos ou conteúdo da chave do Registro aberta.  
  
```
LONG NotifyChangeKeyValue(  
    BOOL bWatchSubtree,
    DWORD dwNotifyFilter,
    HANDLE hEvent,
    BOOL bAsync = TRUE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *bWatchSubtree*  
 Especifica um sinalizador que indica se o relatório alterações na chave especificada e todas as suas subchaves ou apenas na chave especificada. Se esse parâmetro for TRUE, o método relata as alterações na chave e suas subchaves. Se o parâmetro for FALSE, o método relata alterações apenas na chave.  
  
 *dwNotifyFilter*  
 Especifica um conjunto de sinalizadores que controlam as alterações que deve ser relatado. Esse parâmetro pode ser uma combinação dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|REG_NOTIFY_CHANGE_NAME|Notificar o caller se uma subchave é adicionada ou excluída.|  
|REG_NOTIFY_CHANGE_ATTRIBUTES|Notificar o chamador de alterações nos atributos de chave, como as informações do descritor de segurança.|  
|REG_NOTIFY_CHANGE_LAST_SET|Notificar o chamador de alterações para um valor da chave. Isso pode incluir adicionar ou excluir um valor ou alterar um valor existente.|  
|REG_NOTIFY_CHANGE_SECURITY|Notificar o chamador de alterações para o descritor de segurança da chave.|  
  
 `hEvent`  
 Identificador para um evento. Se o *bAsync* parâmetro for TRUE, o método retorna imediatamente e as alterações são relatadas por sinalização esse evento. Se `bAsync` é FALSE, `hEvent` será ignorado.  
  
 `bAsync`  
 Especifica um sinalizador que indica como o método relata as alterações. Se esse parâmetro for TRUE, o método retorna imediatamente e relata alterações por sinalizar o evento especificado. Quando este parâmetro for FALSE, o método não retorna até que a alteração ocorreu. Se `hEvent` não especifica um evento válido, o `bAsync` parâmetro não pode ser TRUE.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Esse método não notifica o chamador se a chave especificada é excluída.  
  
 Para obter mais detalhes e um programa de exemplo, consulte [RegNotifyChangeKeyValue](http://msdn.microsoft.com/library/windows/desktop/ms724892).  
  
##  <a name="open"></a>CRegKey::Open  
 Chame este método para abrir a chave especificada e definir [m_hKey](#m_hkey) no identificador dessa chave.  
  
```
LONG Open(  
    HKEY hKeyParent,
    LPCTSTR lpszKeyName,
    REGSAM samDesired = KEY_READ | KEY_WRITE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hKeyParent`  
 O identificador de uma chave aberta.  
  
 `lpszKeyName`  
 Especifica o nome de uma chave a ser criado ou aberto. Esse nome deve ser uma subchave de `hKeyParent`.  
  
 `samDesired`  
 O acesso de segurança para a chave. O valor padrão é KEY_ALL_ACCESS. Para obter uma lista de possíveis valores e descrições, consulte [RegCreateKeyEx](http://msdn.microsoft.com/library/windows/desktop/ms724844) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará ERROR_SUCCESS; Caso contrário, um valor de erro diferente de zero definido em WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Se o `lpszKeyName` parâmetro é NULL ou pontos para uma cadeia de caracteres vazia, **abrir** abre um novo identificador da chave identificada por `hKeyParent`, mas não feche qualquer identificador aberto anteriormente.  
  
 Ao contrário de [CRegKey::Create](#create), **abrir** não criará a chave especificada, se ele não existe.  
  
##  <a name="operator_hkey"></a>CRegKey::operator HKEY  
 Converte um `CRegKey` objeto para um HKEY.  
  
```  
operator HKEY() const throw();
```  
  
##  <a name="operator_eq"></a>CRegKey::operator =  
 Operador de atribuição.  
  
```
CRegKey& operator= (CRegKey& key) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave para copiar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para a nova chave.  
  
### <a name="remarks"></a>Comentários  
 Este operador desanexa `key` de seu objeto atual e atribui-lo para o `CRegKey` do objeto em vez disso.  
  
##  <a name="querybinaryvalue"></a>CRegKey::QueryBinaryValue  
 Chame este método para recuperar os dados binários para um nome de valor especificado.  
  
```
LONG QueryBinaryValue(  
    LPCTSTR pszValueName,
    void* pValue,
    ULONG* pnBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor para a consulta.  
  
 `pValue`  
 Ponteiro para um buffer que recebe os dados do valor.  
  
 `pnBytes`  
 Ponteiro para uma variável que especifica o tamanho, em bytes, do buffer apontado pelo `pValue` parâmetro. Quando o método retorna, essa variável contém o tamanho dos dados copiados para o buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, será retornado ERROR_SUCCESS. Se o método não conseguir ler um valor, ele retorna um código de erro diferente de zero definido no WINERROR. H. Se os dados de referência não são do tipo REG_BINARY, ERROR_INVALID_DATA será retornado.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa **RegQueryValueEx** e confirma que o tipo de dados correto é retornado. Consulte [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Esse método permite que o chamador pode especificar qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, o [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) função usada por este método não explicitamente lida com cadeias de caracteres que são terminada nula. Ambas as condições devem ser verificadas para o código de chamada.  
  
##  <a name="querydwordvalue"></a>CRegKey::QueryDWORDValue  
 Chame este método para recuperar os dados DWORD para um nome de valor especificado.  
  
```
LONG QueryDWORDValue(  
    LPCTSTR pszValueName,
    DWORD& dwValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor para a consulta.  
  
 `dwValue`  
 Ponteiro para um buffer que recebe o valor DWORD.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, será retornado ERROR_SUCCESS. Se o método não conseguir ler um valor, ele retorna um código de erro diferente de zero definido no WINERROR. H. Se os dados de referência não são do tipo REG_DWORD, ERROR_INVALID_DATA será retornado.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa **RegQueryValueEx** e confirma que o tipo de dados correto é retornado. Consulte [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Esse método permite que o chamador pode especificar qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, o [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) função usada por este método não explicitamente lida com cadeias de caracteres que são terminada nula. Ambas as condições devem ser verificadas para o código de chamada.  
  
##  <a name="queryguidvalue"></a>CRegKey::QueryGUIDValue  
 Chame esse método para recuperar os dados GUID para o nome do valor especificado.  
  
```
LONG QueryGUIDValue(  
    LPCTSTR pszValueName,
    GUID& guidValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor para a consulta.  
  
 `guidValue`  
 Ponteiro para uma variável que recebe o GUID.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, será retornado ERROR_SUCCESS. Se o método não conseguir ler um valor, ele retorna um código de erro diferente de zero definido no WINERROR. H. Se os dados de referência não são uma GUID válida, ERROR_INVALID_DATA será retornado.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa `CRegKey::QueryStringValue` e converte a cadeia de caracteres em um GUID usando [CLSIDFromString](http://msdn.microsoft.com/library/windows/desktop/ms680589).  
  
> [!IMPORTANT]
>  Esse método permite que o chamador pode especificar qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis.  
  
##  <a name="querymultistringvalue"></a>CRegKey::QueryMultiStringValue  
 Chame este método para recuperar os dados de cadeias de caracteres múltiplas para um nome de valor especificado.  
  
```
LONG QueryMultiStringValue(  
    LPCTSTR pszValueName,
    LPTSTR pszValue,
    ULONG* pnChars) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor para a consulta.  
  
 `pszValue`  
 Ponteiro para um buffer que recebe os dados de cadeias de caracteres múltiplas. Uma múltipla de comprimento fixo é uma matriz de cadeias de caracteres terminada em nulo, terminada por dois caracteres nulos.  
  
 `pnChars`  
 O tamanho, em TCHARs, do buffer apontado pelo `pszValue`. Quando o método retorna, `pnChars` contém o tamanho, em TCHARs, da múltipla de comprimento fixo recuperados, incluindo um caractere null de terminação.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, será retornado ERROR_SUCCESS. Se o método não conseguir ler um valor, ele retorna um código de erro diferente de zero definido no WINERROR. H. Se os dados de referência não são do tipo REG_MULTI_SZ, ERROR_INVALID_DATA será retornado.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa **RegQueryValueEx** e confirma que o tipo de dados correto é retornado. Consulte [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Esse método permite que o chamador pode especificar qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, o [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) função usada por este método não explicitamente lida com cadeias de caracteres que são terminada nula. Ambas as condições devem ser verificadas para o código de chamada.  
  
##  <a name="queryqwordvalue"></a>CRegKey::QueryQWORDValue  
 Chame este método para recuperar os dados QWORD para um nome de valor especificado.  
  
```
LONG QueryQWORDValue(  
    LPCTSTR pszValueName,
    ULONGLONG& qwValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor para a consulta.  
  
 `qwValue`  
 Ponteiro para um buffer que recebe o QWORD.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, será retornado ERROR_SUCCESS. Se o método não conseguir ler um valor, ele retorna um código de erro diferente de zero definido no WINERROR. H. Se os dados de referência não são do tipo REG_QWORD, ERROR_INVALID_DATA será retornado.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa **RegQueryValueEx** e confirma que o tipo de dados correto é retornado. Consulte [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Esse método permite que o chamador pode especificar qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, o [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) função usada por este método não explicitamente lida com cadeias de caracteres que são terminada nula. Ambas as condições devem ser verificadas para o código de chamada.  
  
##  <a name="querystringvalue"></a>CRegKey::QueryStringValue  
 Chame este método para recuperar os dados de cadeia de caracteres para um nome de valor especificado.  
  
```
LONG QueryStringValue(  
    LPCTSTR pszValueName,
    LPTSTR pszValue,
    ULONG* pnChars) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor para a consulta.  
  
 `pszValue`  
 Ponteiro para um buffer que recebe os dados de cadeia de caracteres.  
  
 `pnChars`  
 O tamanho, em TCHARs, do buffer apontado pelo `pszValue`. Quando o método retorna, `pnChars` contém o tamanho, em TCHARs, da cadeia de caracteres recuperados, incluindo um caractere null de terminação.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, será retornado ERROR_SUCCESS. Se o método não conseguir ler um valor, ele retorna um código de erro diferente de zero definido no WINERROR. H. Se os dados de referência não são do tipo REG_SZ, ERROR_INVALID_DATA será retornado. Se o método retornar ERROR_MORE_DATA, `pnChars` igual a zero, não o tamanho do buffer necessário em bytes.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa **RegQueryValueEx** e confirma que o tipo de dados correto é retornado. Consulte [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Esse método permite que o chamador pode especificar qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, o [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) função usada por este método não explicitamente lida com cadeias de caracteres que são terminada nula. Ambas as condições devem ser verificadas para o código de chamada.  
  
##  <a name="queryvalue"></a>CRegKey::QueryValue  
 Chame esse método para recuperar os dados para o campo de valor especificado de [m_hKey](#m_hkey). Versões anteriores deste método não têm mais suporte e são marcadas como **ATL_DEPRECATED**.  
  
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
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do valor para a consulta. Se `pszValueName` é nulo ou uma cadeia de caracteres vazia "", o método recupera o tipo e os dados para a chave sem nome ou valor padrão, se houver.  
  
 `pdwType`  
 Ponteiro para uma variável que recebe um código que indica o tipo de dados armazenados no valor especificado. O `pdwType` parâmetro pode ser NULL se o código de tipo não é necessário.  
  
 `pData`  
 Ponteiro para um buffer que recebe os dados do valor. Esse parâmetro pode ser NULL se os dados não são necessários.  
  
 `pnBytes`  
 Ponteiro para uma variável que especifica o tamanho, em bytes, do buffer apontado pelo `pData` parâmetro. Quando o método retorna, essa variável contém o tamanho dos dados copiados *pData.*  
  
 `dwValue`  
 Dados numéricos do campo de valor.  
  
 `lpszValueName`  
 Especifica o campo de valor a ser consultado.  
  
 `szValue`  
 Dados de cadeia de caracteres do campo de valor.  
  
 `pdwCount`  
 O tamanho dos dados de cadeia de caracteres. Seu valor é definido inicialmente como o tamanho do `szValue` buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará ERROR_SUCCESS; Caso contrário, um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 As duas versões originais do `QueryValue` não têm mais suporte e são marcados como **ATL_DEPRECATED**. O compilador emitirá um aviso se esses formulários são usados.  
  
 As chamadas de método restantes RegQueryValueEx.  
  
> [!IMPORTANT]
>  Esse método permite que o chamador pode especificar qualquer local do registro, potencialmente lendo dados que não podem ser confiáveis. Além disso, a função de RegQueryValueEx usada por este método não explicitamente trata cadeias de caracteres que são `NULL` encerrada. Ambas as condições devem ser verificadas para o código de chamada.  
  
##  <a name="recursedeletekey"></a>CRegKey::RecurseDeleteKey  
 Chame esse método para remover a chave especificada do registro e remover explicitamente todas as subchaves.  
  
```
LONG RecurseDeleteKey(LPCTSTR lpszKey) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszKey*  
 Especifica o nome da chave para excluir. Esse nome deve ser uma subchave de [m_hKey](#m_hkey).  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará ERROR_SUCCESS; Caso contrário, um valor de erro diferente de zero definido em WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Se a chave tem subchaves, você deve chamar esse método para excluir a chave.  
  
##  <a name="setbinaryvalue"></a>CRegKey::SetBinaryValue  
 Chame este método para definir o valor binário da chave do registro.  
  
```
LONG SetBinaryValue(  
    LPCTSTR pszValueName,
    const void* pValue,
    ULONG nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com este nome já não estiver presente, o método o adiciona à chave.  
  
 `pValue`  
 Ponteiro para um buffer que contém os dados a ser armazenado com o nome do valor especificado.  
  
 `nBytes`  
 Especifica o tamanho, em bytes, das informações que aponta para o `pValue` parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa [RegSetValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724923) para gravar o valor do registro.  
  
##  <a name="setdwordvalue"></a>CRegKey::SetDWORDValue  
 Chame este método para definir o valor DWORD da chave do registro.  
  
```
LONG SetDWORDValue(LPCTSTR pszValueName, DWORD dwValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com este nome já não estiver presente, o método o adiciona à chave.  
  
 `dwValue`  
 Os dados DWORD a ser armazenado com o nome do valor especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa [RegSetValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724923) para gravar o valor do registro.  
  
##  <a name="setguidvalue"></a>CRegKey::SetGUIDValue  
 Chame este método para definir o valor GUID da chave do registro.  
  
```
LONG SetGUIDValue(LPCTSTR pszValueName, REFGUID guidValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com este nome já não estiver presente, o método o adiciona à chave.  
  
 `guidValue`  
 Referência para o GUID a ser armazenado com o nome do valor especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa `CRegKey::SetStringValue` e converte o GUID em uma cadeia de caracteres usando [StringFromGUID2](http://msdn.microsoft.com/library/windows/desktop/ms683893).  
  
##  <a name="setkeyvalue"></a>CRegKey::SetKeyValue  
 Chame esse método para armazenar dados em um campo de valor especificado de uma chave especificada.  
  
```
LONG SetKeyValue(  
    LPCTSTR lpszKeyName,
    LPCTSTR lpszValue,
    LPCTSTR lpszValueName = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszKeyName`  
 Especifica o nome da chave a ser criado ou aberto. Esse nome deve ser uma subchave de [m_hKey](#m_hkey).  
  
 `lpszValue`  
 Especifica os dados a ser armazenado. Esse parâmetro deve ser não-nulo.  
  
 `lpszValueName`  
 Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará ERROR_SUCCESS; Caso contrário, um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para criar ou abrir o `lpszKeyName` chave e armazenar o `lpszValue` dados no `lpszValueName` campo de valor.  
  
##  <a name="setkeysecurity"></a>CRegKey::SetKeySecurity  
 Chame esse método para definir a segurança da chave do registro.  
  
```
LONG SetKeySecurity(SECURITY_INFORMATION si, PSECURITY_DESCRIPTOR psd) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `si`  
 Especifica os componentes do descritor de segurança para definir. O valor pode ser uma combinação dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|DACL_SECURITY_INFORMATION|Define a lista da chave de controle de acesso discricionário (DACL). A chave deve ter acesso WRITE_DAC ou o processo de chamada deve ser o proprietário do objeto.|  
|GROUP_SECURITY_INFORMATION|Define o identificador de segurança da chave primária de grupo (SID). A chave deve ter acesso WRITE_OWNER ou o processo de chamada deve ser o proprietário do objeto.|  
|OWNER_SECURITY_INFORMATION|Define o proprietário da chave SID. A chave deve ter acesso WRITE_OWNER ou o processo de chamada deve ser o proprietário do objeto ou ter o privilégio SE_TAKE_OWNERSHIP_NAME habilitado.|  
|SACL_SECURITY_INFORMATION|Define a lista de controle de acesso a chave sistema (SACL). A chave deve ter acesso ACCESS_SYSTEM_SECURITY. O modo adequado para obter esse acesso é habilitar o SE_SECURITY_NAME [privilégio](http://msdn.microsoft.com/library/windows/desktop/aa379306) no token de acesso atual do chamador, abrir o identificador para o acesso ACCESS_SYSTEM_SECURITY e, em seguida, desabilite o privilégio.|  
  
 `psd`  
 Ponteiro para um [SECURITY_DESCRIPTOR](http://msdn.microsoft.com/library/windows/desktop/aa379561) estrutura que especifica os atributos de segurança a ser definido para a chave especificada.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Define os atributos de segurança da chave. Consulte [RegSetKeySecurity](http://msdn.microsoft.com/library/windows/desktop/aa379314) para obter mais detalhes.  
  
##  <a name="setmultistringvalue"></a>CRegKey::SetMultiStringValue  
 Chame este método para definir um valor de chave de registro.  
  
```
LONG SetMultiStringValue(LPCTSTR pszValueName, LPCTSTR pszValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com este nome já não estiver presente, o método o adiciona à chave.  
  
 `pszValue`  
 Ponteiro para os dados de cadeias de caracteres múltiplas a ser armazenado com o nome do valor especificado. Uma múltipla de comprimento fixo é uma matriz de cadeias de caracteres terminada em nulo, terminada por dois caracteres nulos.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa [RegSetValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724923) para gravar o valor do registro.  
  
##  <a name="setqwordvalue"></a>CRegKey::SetQWORDValue  
 Chame este método para definir o valor QWORD da chave do registro.  
  
```
LONG SetQWORDValue(LPCTSTR pszValueName, ULONGLONG qwValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com este nome já não estiver presente, o método o adiciona à chave.  
  
 `qwValue`  
 Os dados QWORD a ser armazenado com o nome do valor especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa [RegSetValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724923) para gravar o valor do registro.  
  
##  <a name="setstringvalue"></a>CRegKey::SetStringValue  
 Chame este método para definir o valor de cadeia de caracteres da chave do registro.  
  
```
LONG SetStringValue(  
    LPCTSTR pszValueName,
    LPCTSTR pszValue,
    DWORD dwType = REG_SZ) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com este nome já não estiver presente, o método o adiciona à chave.  
  
 `pszValue`  
 Ponteiro para os dados de cadeia de caracteres a ser armazenado com o nome do valor especificado.  
  
 `dwType`  
 O tipo de cadeia de caracteres para escrever no registro: REG_SZ (o padrão) ou REG_EXPAND_SZ (para cadeias de caracteres múltiplas).  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, o valor de retorno é ERROR_SUCCESS. Se o método falhar, o valor de retorno é um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa [RegSetValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724923\(v=vs.85\).aspx) para gravar o valor do registro.  
  
##  <a name="setvalue"></a>CRegKey::SetValue  
 Chame esse método para armazenar dados no campo de valor especificado de [m_hKey](#m_hkey). Versões anteriores deste método não têm mais suporte e são marcadas como **ATL_DEPRECATED**.  
  
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
 `pszValueName`  
 Ponteiro para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com este nome já não estiver presente na chave, o método o adiciona à chave. Se `pszValueName` é nulo ou uma cadeia de caracteres vazia "", o método define o tipo e os dados para a chave sem nome ou valor padrão.  
  
 `dwType`  
 Especifica um código que indica o tipo de dados que aponta para o `pValue` parâmetro.  
  
 `pValue`  
 Ponteiro para um buffer que contém os dados a ser armazenado com o nome do valor especificado.  
  
 `nBytes`  
 Especifica o tamanho, em bytes, das informações que aponta para o `pValue` parâmetro. Se os dados forem do tipo REG_SZ, REG_EXPAND_SZ ou REG_MULTI_SZ `nBytes` deve incluir o tamanho do caractere null de terminação.  
  
 `hKeyParent`  
 O identificador de uma chave aberta.  
  
 `lpszKeyName`  
 Especifica o nome de uma chave a ser criado ou aberto. Esse nome deve ser uma subchave de `hKeyParent`.  
  
 `lpszValue`  
 Especifica os dados a ser armazenado. Esse parâmetro deve ser não-nulo.  
  
 `lpszValueName`  
 Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.  
  
 `dwValue`  
 Especifica os dados a ser armazenado.  
  
 `bMulti`  
 Se for false, indica que a cadeia de caracteres é do tipo REG_SZ. Se for true, indica que a cadeia de caracteres é uma múltipla de comprimento fixo do tipo REG_MULTI_SZ.  
  
 `nValueLen`  
 Se `bMulti` for true, `nValueLen` é o comprimento do *lpszValue* cadeia de caracteres. Se `bMulti` for false, um valor de -1 indica que o método irá calcular automaticamente o comprimento.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará ERROR_SUCCESS; Caso contrário, um código de erro diferente de zero definido no WINERROR. H.  
  
### <a name="remarks"></a>Comentários  
 As duas versões originais do `SetValue` são marcados como **ATL_DEPRECATED** e não deve mais ser usado. O compilador emitirá um aviso se esses formulários são usados.  
  
 As terceiros chamadas de método [RegSetValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724923).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo DCOM](../../visual-cpp-samples.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
