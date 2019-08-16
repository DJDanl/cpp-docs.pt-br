---
title: Classe COleObjectFactory
ms.date: 11/04/2016
f1_keywords:
- COleObjectFactory
- AFXDISP/COleObjectFactory
- AFXDISP/COleObjectFactory::COleObjectFactory
- AFXDISP/COleObjectFactory::GetClassID
- AFXDISP/COleObjectFactory::IsLicenseValid
- AFXDISP/COleObjectFactory::IsRegistered
- AFXDISP/COleObjectFactory::Register
- AFXDISP/COleObjectFactory::RegisterAll
- AFXDISP/COleObjectFactory::Revoke
- AFXDISP/COleObjectFactory::RevokeAll
- AFXDISP/COleObjectFactory::UnregisterAll
- AFXDISP/COleObjectFactory::UpdateRegistry
- AFXDISP/COleObjectFactory::UpdateRegistryAll
- AFXDISP/COleObjectFactory::GetLicenseKey
- AFXDISP/COleObjectFactory::OnCreateObject
- AFXDISP/COleObjectFactory::VerifyLicenseKey
- AFXDISP/COleObjectFactory::VerifyUserLicense
helpviewer_keywords:
- COleObjectFactory [MFC], COleObjectFactory
- COleObjectFactory [MFC], GetClassID
- COleObjectFactory [MFC], IsLicenseValid
- COleObjectFactory [MFC], IsRegistered
- COleObjectFactory [MFC], Register
- COleObjectFactory [MFC], RegisterAll
- COleObjectFactory [MFC], Revoke
- COleObjectFactory [MFC], RevokeAll
- COleObjectFactory [MFC], UnregisterAll
- COleObjectFactory [MFC], UpdateRegistry
- COleObjectFactory [MFC], UpdateRegistryAll
- COleObjectFactory [MFC], GetLicenseKey
- COleObjectFactory [MFC], OnCreateObject
- COleObjectFactory [MFC], VerifyLicenseKey
- COleObjectFactory [MFC], VerifyUserLicense
ms.assetid: ab179c1e-4af2-44aa-a576-37c48149b427
ms.openlocfilehash: 22805550d13ecb400b151495363e5eda2dfb3b76
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503736"
---
# <a name="coleobjectfactory-class"></a>Classe COleObjectFactory

Implementa a fábrica de classes OLE, que cria objetos OLE, como servidores, objetos de automação e documentos.

## <a name="syntax"></a>Sintaxe

```
class COleObjectFactory : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleObjectFactory::COleObjectFactory](#coleobjectfactory)|Constrói um objeto `COleObjectFactory`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleObjectFactory::GetClassID](#getclassid)|Retorna a ID da classe OLE dos objetos que esta fábrica cria.|
|[COleObjectFactory::IsLicenseValid](#islicensevalid)|Determina se a licença do controle é válida.|
|[COleObjectFactory::IsRegistered](#isregistered)|Indica se a fábrica de objetos está registrada com as DLLs do sistema OLE.|
|[COleObjectFactory::Register](#register)|Registra esse alocador de objeto com as DLLs do sistema OLE.|
|[COleObjectFactory::RegisterAll](#registerall)|Registra todas as fábricas de objeto do aplicativo com DLLs do sistema OLE.|
|[COleObjectFactory::Revoke](#revoke)|Revoga o registro desta fábrica de objetos com as DLLs do sistema OLE.|
|[COleObjectFactory::RevokeAll](#revokeall)|Revoga os registros de fábricas de objeto de um aplicativo com as DLLs do sistema OLE.|
|[COleObjectFactory::UnregisterAll](#unregisterall)|Cancela o registro de todas as fábricas de objeto de um aplicativo.|
|[COleObjectFactory::UpdateRegistry](#updateregistry)|Registra essa fábrica de objetos com o registro do sistema OLE.|
|[COleObjectFactory::UpdateRegistryAll](#updateregistryall)|Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleObjectFactory::GetLicenseKey](#getlicensekey)|Solicita uma chave exclusiva da DLL do controle.|
|[COleObjectFactory::OnCreateObject](#oncreateobject)|Chamado pelo Framework para criar um novo objeto do tipo desta fábrica.|
|[COleObjectFactory::VerifyLicenseKey](#verifylicensekey)|Verifica se a chave inserida no controle corresponde à chave inserida no contêiner.|
|[COleObjectFactory::VerifyUserLicense](#verifyuserlicense)|Verifica se o controle é licenciado para uso em tempo de design.|

## <a name="remarks"></a>Comentários

A `COleObjectFactory` classe tem funções membro para executar as seguintes funções:

- Gerenciando o registro de objetos.

- Atualizar o registro do sistema OLE, bem como o registro em tempo de execução que informa ao OLE que os objetos estão em execução e prontos para receber mensagens.

- Impor o licenciamento limitando o uso do controle aos desenvolvedores licenciados em tempo de design e a aplicativos licenciados em tempo de execução.

- Registrando fábricas de objeto de controle com o registro do sistema OLE.

Para obter mais informações sobre a criação de objetos, consulte os artigos objetos de dados [e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md) e [objetos de dados e fontes de dados: Criação e destruição](../../mfc/data-objects-and-data-sources-creation-and-destruction.md). Para obter mais informações sobre o registro, consulte o artigo [registro](../../mfc/registration.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleObjectFactory`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

##  <a name="coleobjectfactory"></a>  COleObjectFactory::COleObjectFactory

Constrói um `COleObjectFactory` objeto, inicializa-o como uma fábrica de objetos não registrados e o adiciona à lista de fábricas.

```
COleObjectFactory(
    REFCLSID clsid,
    CRuntimeClass* pRuntimeClass,
    BOOL bMultiInstance,
    LPCTSTR lpszProgID);

COleObjectFactory(
    REFCLSID clsid,
    CRuntimeClass* pRuntimeClass,
    BOOL bMultiInstance,
    int nFlags,
    LPCTSTR lpszProgID);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
Referência à ID de classe OLE que esta fábrica de objeto representa.

*pRuntimeClass*<br/>
Ponteiro para a classe de tempo de execução dos C++ objetos que essa fábrica pode criar.

*bMultiInstance*<br/>
Indica se uma única instância do aplicativo pode dar suporte a várias instanciações. Se for TRUE, várias instâncias do aplicativo serão iniciadas para cada solicitação para criar um objeto.

*nFlags*<br/>
Contém um ou mais dos seguintes sinalizadores:

- `afxRegDefault`Define o modelo de Threading como ThreadingModel = Apartment.

- `afxRegInsertable`Permite que o controle apareça na caixa de diálogo **Inserir objeto** para objetos OLE.

- `afxRegApartmentThreading`Define o modelo de threading no registro como ThreadingModel = Apartment.

- `afxRegFreeThreading`Define o modelo de threading no registro como ThreadingModel = Free.

   Você pode combinar os dois sinalizadores `afxRegApartmentThreading` e `afxRegFreeThreading` definir ThreadingModel = ambos. Consulte [InprocServer32](/windows/win32/com/inprocserver32) no SDK do Windows para obter mais informações sobre o registro do modelo de Threading.

*lpszProgID*<br/>
Ponteiro para uma cadeia de caracteres que contém um identificador de programa textual, como "Microsoft Excel".

### <a name="remarks"></a>Comentários

No entanto, para usar o objeto, você deve registrá-lo.

Para obter mais informações, consulte [chave de CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

##  <a name="getclassid"></a>  COleObjectFactory::GetClassID

Retorna uma referência à ID de classe OLE que essa fábrica representa.

```
REFCLSID GetClassID() const;
```

### <a name="return-value"></a>Valor de retorno

Referência à ID de classe OLE que esta fábrica representa.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [chave de CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

##  <a name="getlicensekey"></a>  COleObjectFactory::GetLicenseKey

Solicita uma chave de licença exclusiva da DLL do controle e a armazena no BSTR apontado por *pbstrKey*.

```
virtual BOOL GetLicenseKey(
    DWORD dwReserved,
    BSTR* pbstrKey);
```

### <a name="parameters"></a>Parâmetros

*dwReserved*<br/>
Reservado para uso futuro.

*pbstrKey*<br/>
Ponteiro para um BSTR que irá armazenar a chave de licença.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a cadeia de caracteres da chave de licença não for nula; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função retorna 0 e não armazena nada no BSTR. Se você usar o ControlWizard ActiveX do MFC para criar seu projeto, o ControlWizard fornecerá uma substituição que recupera a chave de licença do controle.

##  <a name="islicensevalid"></a>  COleObjectFactory::IsLicenseValid

Determina se a licença do controle é válida.

```
BOOL IsLicenseValid();
```

### <a name="return-value"></a>Valor de retorno

TRUE se successul; caso contrário, false.

##  <a name="isregistered"></a>  COleObjectFactory::IsRegistered

Retornará um valor diferente de zero se a fábrica estiver registrada com as DLLs do sistema OLE.

```
virtual BOOL IsRegistered() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fábrica estiver registrada; caso contrário, 0.

##  <a name="oncreateobject"></a>  COleObjectFactory::OnCreateObject

Chamado pelo Framework para criar um novo objeto.

```
virtual CCmdTarget* OnCreateObject();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto criado. Ele pode gerar uma exceção de memória se falhar.

### <a name="remarks"></a>Comentários

Substitua essa função para criar o objeto de algo diferente do [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) passado para o construtor.

##  <a name="register"></a>  COleObjectFactory::Register

Registra esse alocador de objeto com as DLLs do sistema OLE.

```
virtual BOOL Register();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fábrica for registrada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é geralmente chamada por [CWinApp:: InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.

##  <a name="registerall"></a>  COleObjectFactory::RegisterAll

Registra todas as fábricas de objeto do aplicativo com as DLLs do sistema OLE.

```
static BOOL PASCAL RegisterAll();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as fábricas forem registradas com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é geralmente chamada por [CWinApp:: InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.

##  <a name="revoke"></a>  COleObjectFactory::Revoke

Revoga o registro desta fábrica de objetos com as DLLs do sistema OLE.

```
void Revoke();
```

### <a name="remarks"></a>Comentários

A estrutura chama essa função automaticamente antes de o aplicativo ser encerrado. Se necessário, chame-o de uma substituição de [CWinApp:: ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).

##  <a name="revokeall"></a>  COleObjectFactory::RevokeAll

Revoga todos os registros de fábricas de objeto do aplicativo com as DLLs do sistema OLE.

```
static void PASCAL RevokeAll();
```

### <a name="remarks"></a>Comentários

A estrutura chama essa função automaticamente antes de o aplicativo ser encerrado. Se necessário, chame-o de uma substituição de [CWinApp:: ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).

##  <a name="unregisterall"></a>  COleObjectFactory::UnregisterAll

Cancela o registro de todas as fábricas de objeto de um aplicativo.

```
static BOOL PASCAL UnregisterAll();
```

### <a name="return-value"></a>Valor de retorno

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

##  <a name="updateregistry"></a>  COleObjectFactory::UpdateRegistry

Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.

```
void UpdateRegistry(LPCTSTR lpszProgID = NULL);
virtual BOOL UpdateRegistry(BOOL bRegister);
```

### <a name="parameters"></a>Parâmetros

*lpszProgID*<br/>
Ponteiro para uma cadeia de caracteres que contém o identificador de programa legível por humanos, como "Excel. Document. 5."

*bRegister*<br/>
Determina se a fábrica de objetos da classe de controle deve ser registrada.

### <a name="remarks"></a>Comentários

As breves discussões dos dois formulários para essa função são as seguintes:

- **UpdateRegistry (** `lpszProgID` **)** registra esse alocador de objeto com o registro do sistema OLE. Essa função é geralmente chamada por [CWinApp:: InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.

- **UpdateRegistry (** `bRegister` **)** esta forma da função é substituível. Se *bRegister* for true, essa função registrará a classe de controle com o registro do sistema. Caso contrário, ele cancelará o registro da classe.

   Se você usar o ControlWizard ActiveX do MFC para criar seu projeto, o ControlWizard fornecerá uma substituição para essa função virtual pura.

##  <a name="updateregistryall"></a>  COleObjectFactory::UpdateRegistryAll

Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.

```
static BOOL PASCAL UpdateRegistryAll(BOOL bRegister = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bRegister*<br/>
Determina se a fábrica de objetos da classe de controle deve ser registrada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as fábricas forem atualizadas com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é geralmente chamada por [CWinApp:: InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.

##  <a name="verifylicensekey"></a>  COleObjectFactory::VerifyLicenseKey

Verifica se o contêiner está licenciado para usar o controle OLE.

```
virtual BOOL VerifyLicenseKey(BSTR bstrKey);
```

### <a name="parameters"></a>Parâmetros

*bstrKey*<br/>
Um BSTR que armazena a versão do contêiner da cadeia de caracteres de licença.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a licença de tempo de execução for válida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A versão padrão chama [GetLicenseKey](#getlicensekey) para obter uma cópia da cadeia de caracteres de licença do controle e a compara com a cadeia de caracteres em *bstrKey*. Se as duas cadeias de caracteres corresponderem, a função retornará um valor diferente de zero; caso contrário, retornará 0.

Você pode substituir essa função para fornecer a verificação personalizada da licença.

A função [VerifyUserLicense](#verifyuserlicense) verifica a licença de tempo de design.

##  <a name="verifyuserlicense"></a>  COleObjectFactory::VerifyUserLicense

Verifica a licença de tempo de design para o controle OLE.

```
virtual BOOL VerifyUserLicense();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a licença de tempo de design for válida; caso contrário, 0.

## <a name="see-also"></a>Consulte também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
