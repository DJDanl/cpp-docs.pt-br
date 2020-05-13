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
ms.openlocfilehash: 165ba7c1918c3ccc5d5d7e0bc067fba86678a3e7
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753810"
---
# <a name="coleobjectfactory-class"></a>Classe COleObjectFactory

Implementa a fábrica de classe OLE, que cria objetos OLE, como servidores, objetos de automação e documentos.

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
|[COleObjectFactory::GetClassID](#getclassid)|Retorna o ID de classe OLE dos objetos que esta fábrica cria.|
|[COleObjectFactory::IsLicenseValid](#islicensevalid)|Determina se a licença do controle é válida.|
|[COleObjectFactory::ÉRegistrado](#isregistered)|Indica se a fábrica de objetos está registrada nos DLLs do sistema OLE.|
|[COleObjectFactory::Register](#register)|Registra esta fábrica de objetos com os DLLs do sistema OLE.|
|[COleObjectFactory::RegisterAll](#registerall)|Registra todas as fábricas de objetos do aplicativo com DLLs do sistema OLE.|
|[COleObjectFactory::Revogar](#revoke)|Revoga o registro desta fábrica de objetos com as DLLs do sistema OLE.|
|[COleObjectFactory::RevokeAll](#revokeall)|Revoga os registros das fábricas de objetos de um aplicativo com as DLLs do sistema OLE.|
|[COleObjectFactory::UnregisterAll](#unregisterall)|Desregistra todas as fábricas de objetos de um aplicativo.|
|[COleObjectFactory::UpdateRegistry](#updateregistry)|Registra esta fábrica de objetos com o registro do sistema OLE.|
|[COleObjectFactory::UpdateRegistryAll](#updateregistryall)|Registra todas as fábricas de objetos do aplicativo com o registro do sistema OLE.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleObjectFactory::GetLicenseKey](#getlicensekey)|Solicita uma chave única da DLL do controle.|
|[COleObjectFactory::OnCreateObject](#oncreateobject)|Chamado pela estrutura para criar um novo objeto do tipo desta fábrica.|
|[COleObjectFactory::VerifyLicenseKey](#verifylicensekey)|Verifica se a chave embutida no controle corresponde à chave embutida no recipiente.|
|[COleObjectFactory::VerificarLicença do usuário](#verifyuserlicense)|Verifica se o controle é licenciado para uso em tempo de projeto.|

## <a name="remarks"></a>Comentários

A `COleObjectFactory` classe tem funções de membro para executar as seguintes funções:

- Gerenciando o registro de objetos.

- Atualizando o registro do sistema OLE, bem como o registro de tempo de execução que informa o OLE de que os objetos estão em execução e prontos para receber mensagens.

- Imposição do licenciamento limitando o uso do controle a desenvolvedores licenciados no momento do projeto e a aplicativos licenciados em tempo de execução.

- Registrando fábricas de objetos de controle com o registro do sistema OLE.

Para obter mais informações sobre a criação de objetos, consulte os artigos [Objetos de Dados e Fontes de Dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md) e [Objetos de Dados e Fontes de Dados: Criação e Destruição](../../mfc/data-objects-and-data-sources-creation-and-destruction.md). Para mais informações sobre inscrição, consulte o artigo [Registro](../../mfc/registration.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`COleObjectFactory`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="coleobjectfactorycoleobjectfactory"></a><a name="coleobjectfactory"></a>COleObjectFactory::COleObjectFactory

Constrói um `COleObjectFactory` objeto, inicializa-o como uma fábrica de objetos não registrados e adiciona-o à lista de fábricas.

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
Referência ao ID de classe OLE que esta fábrica de objetos representa.

*pRuntimeClass*<br/>
Ponteiro para a classe de tempo de execução dos objetos C++ que esta fábrica pode criar.

*bMultiInstance*<br/>
Indica se uma única instância do aplicativo pode suportar múltiplas instanciações. Se TRUE, várias instâncias do aplicativo são lançadas para cada solicitação criar um objeto.

*Nflags*<br/>
Contém uma ou mais das seguintes bandeiras:

- `afxRegDefault`Define o modelo de rosca como ThreadingModel=Apartment.

- `afxRegInsertable`Permite que o controle apareça na caixa de diálogo **Inserir objeto** para objetos OLE.

- `afxRegApartmentThreading`Define o modelo de rosca no registro como ThreadingModel=Apartment.

- `afxRegFreeThreading`Define o modelo de rosca no registro como ThreadingModel=Free.

   Você pode combinar `afxRegApartmentThreading` as `afxRegFreeThreading` duas bandeiras e definir ThreadingModel=Both. Consulte [InprocServer32](/windows/win32/com/inprocserver32) no SDK do Windows para obter mais informações sobre o registro do modelo de threading.

*lpszProgID*<br/>
Ponteiro para uma seqüência contendo um identificador de programa verbal, como "Microsoft Excel".

### <a name="remarks"></a>Comentários

Para usar o objeto, no entanto, você deve registrá-lo.

Para obter mais informações, consulte [a tecla CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

## <a name="coleobjectfactorygetclassid"></a><a name="getclassid"></a>COleObjectFactory::GetClassID

Retorna uma referência ao ID de classe OLE que esta fábrica representa.

```
REFCLSID GetClassID() const;
```

### <a name="return-value"></a>Valor retornado

Referência ao ID de classe OLE que esta fábrica representa.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [a tecla CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

## <a name="coleobjectfactorygetlicensekey"></a><a name="getlicensekey"></a>COleObjectFactory::GetLicenseKey

Solicita uma chave de licença exclusiva da DLL do controle e armazena-a no BSTR apontado por *pbstrKey*.

```
virtual BOOL GetLicenseKey(
    DWORD dwReserved,
    BSTR* pbstrKey);
```

### <a name="parameters"></a>Parâmetros

*dwReservado*<br/>
Reservado para uso futuro.

*pbstrKey*<br/>
Ponteiro para um BSTR que armazenará a chave de licença.

### <a name="return-value"></a>Valor retornado

Não zero se a seqüência de teclas de licença não for NULA; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão desta função retorna 0 e não armazena nada no BSTR. Se você usar o MFC ActiveX ControlWizard para criar seu projeto, o ControlWizard fornece uma substituição que recupera a chave de licença do controle.

## <a name="coleobjectfactoryislicensevalid"></a><a name="islicensevalid"></a>COleObjectFactory::IsLicenseValid

Determina se a licença do controle é válida.

```
BOOL IsLicenseValid();
```

### <a name="return-value"></a>Valor retornado

VERDADE se sucessoul; caso contrário, falso.

## <a name="coleobjectfactoryisregistered"></a><a name="isregistered"></a>COleObjectFactory::ÉRegistrado

Retorna um valor não zero se a fábrica estiver registrada nas DLLs do sistema OLE.

```
virtual BOOL IsRegistered() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a fábrica estiver registrada; caso contrário, 0.

## <a name="coleobjectfactoryoncreateobject"></a><a name="oncreateobject"></a>COleObjectFactory::OnCreateObject

Chamado pela estrutura para criar um novo objeto.

```
virtual CCmdTarget* OnCreateObject();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto criado. Pode abrir uma exceção de memória se falhar.

### <a name="remarks"></a>Comentários

Substituir esta função para criar o objeto a partir de algo diferente do [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) passado para o construtor.

## <a name="coleobjectfactoryregister"></a><a name="register"></a>COleObjectFactory::Register

Registra esta fábrica de objetos com os DLLs do sistema OLE.

```
virtual BOOL Register();
```

### <a name="return-value"></a>Valor retornado

Não zero se a fábrica for registrada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é geralmente chamada por [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.

## <a name="coleobjectfactoryregisterall"></a><a name="registerall"></a>COleObjectFactory::RegisterAll

Registra todas as fábricas de objetos do aplicativo com os DLLs do sistema OLE.

```
static BOOL PASCAL RegisterAll();
```

### <a name="return-value"></a>Valor retornado

Não zero se as fábricas forem registradas com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é geralmente chamada por [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.

## <a name="coleobjectfactoryrevoke"></a><a name="revoke"></a>COleObjectFactory::Revogar

Revoga o registro desta fábrica de objetos com as DLLs do sistema OLE.

```cpp
void Revoke();
```

### <a name="remarks"></a>Comentários

O framework chama essa função automaticamente antes do aplicativo ser encerrado. Se necessário, ligue-o a partir de uma substituição de [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).

## <a name="coleobjectfactoryrevokeall"></a><a name="revokeall"></a>COleObjectFactory::RevokeAll

Revoga todos os registros das fábricas de objetos do aplicativo com as DLLs do sistema OLE.

```
static void PASCAL RevokeAll();
```

### <a name="remarks"></a>Comentários

O framework chama essa função automaticamente antes do aplicativo ser encerrado. Se necessário, ligue-o a partir de uma substituição de [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).

## <a name="coleobjectfactoryunregisterall"></a><a name="unregisterall"></a>COleObjectFactory::UnregisterAll

Desregistra todas as fábricas de objetos de um aplicativo.

```
static BOOL PASCAL UnregisterAll();
```

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

## <a name="coleobjectfactoryupdateregistry"></a><a name="updateregistry"></a>COleObjectFactory::UpdateRegistry

Registra todas as fábricas de objetos do aplicativo com o registro do sistema OLE.

```cpp
void UpdateRegistry(LPCTSTR lpszProgID = NULL);
virtual BOOL UpdateRegistry(BOOL bRegister);
```

### <a name="parameters"></a>Parâmetros

*lpszProgID*<br/>
Ponteiro para uma seqüência contendo o identificador de programa legível por humanos, como "Excel.Document.5".

*Bregister*<br/>
Determina se a fábrica de objetos da classe de controle deve ser registrada.

### <a name="remarks"></a>Comentários

Breves discussões sobre as duas formas para esta função seguem:

- **Registro de Atualização(** `lpszProgID` **)** Registra esta fábrica de objetos com o registro do sistema OLE. Essa função é geralmente chamada por [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.

- **Registro de Atualização(** `bRegister` **)** Esta forma da função é superridível. Se *bRegister* for TRUE, esta função registrará a classe de controle com o registro do sistema. Caso contrário, ele desregistra a classe.

   Se você usar o MFC ActiveX ControlWizard para criar seu projeto, o ControlWizard fornece uma substituição a essa função virtual pura.

## <a name="coleobjectfactoryupdateregistryall"></a><a name="updateregistryall"></a>COleObjectFactory::UpdateRegistryAll

Registra todas as fábricas de objetos do aplicativo com o registro do sistema OLE.

```
static BOOL PASCAL UpdateRegistryAll(BOOL bRegister = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bregister*<br/>
Determina se a fábrica de objetos da classe de controle deve ser registrada.

### <a name="return-value"></a>Valor retornado

Não zero se as fábricas forem atualizadas com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é geralmente chamada por [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.

## <a name="coleobjectfactoryverifylicensekey"></a><a name="verifylicensekey"></a>COleObjectFactory::VerifyLicenseKey

Verifica se o contêiner está licenciado para usar o controle OLE.

```
virtual BOOL VerifyLicenseKey(BSTR bstrKey);
```

### <a name="parameters"></a>Parâmetros

*bstrKey*<br/>
Um BSTR armazenando a versão do recipiente da seqüência de licenças.

### <a name="return-value"></a>Valor retornado

Não zero se a licença de tempo de execução for válida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A versão padrão chama [GetLicenseKey](#getlicensekey) para obter uma cópia da seqüência de licença saem do controle e a compara com a string em *bstrKey*. Se as duas strings coincidirem, a função retorna um valor não zero; caso contrário, ele retorna 0.

Você pode substituir esta função para fornecer verificação personalizada da licença.

A função [VerifyUserLicense](#verifyuserlicense) verifica a licença de tempo de projeto.

## <a name="coleobjectfactoryverifyuserlicense"></a><a name="verifyuserlicense"></a>COleObjectFactory::VerificarLicença do usuário

Verifica a licença de tempo de projeto para o controle OLE.

```
virtual BOOL VerifyUserLicense();
```

### <a name="return-value"></a>Valor retornado

Não zero se a licença de tempo de projeto for válida; caso contrário, 0.

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
