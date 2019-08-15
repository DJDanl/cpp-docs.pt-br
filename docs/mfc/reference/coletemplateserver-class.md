---
title: Classe COleTemplateServer
ms.date: 11/04/2016
f1_keywords:
- COleTemplateServer
- AFXDISP/COleTemplateServer
- AFXDISP/COleTemplateServer::COleTemplateServer
- AFXDISP/COleTemplateServer::ConnectTemplate
- AFXDISP/COleTemplateServer::Unregister
- AFXDISP/COleTemplateServer::UpdateRegistry
helpviewer_keywords:
- COleTemplateServer [MFC], COleTemplateServer
- COleTemplateServer [MFC], ConnectTemplate
- COleTemplateServer [MFC], Unregister
- COleTemplateServer [MFC], UpdateRegistry
ms.assetid: 47a2887d-8162-4993-a842-a784177c7f5c
ms.openlocfilehash: 4a1997497f3bddb405b712b5534f76e577dabfa8
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503090"
---
# <a name="coletemplateserver-class"></a>Classe COleTemplateServer

Usado para servidores de edição Visual OLE, servidores de automação e contêineres de link (aplicativos que dão suporte a links para incorporações).

## <a name="syntax"></a>Sintaxe

```
class COleTemplateServer : public COleObjectFactory
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleTemplateServer::COleTemplateServer](#coletemplateserver)|Constrói um objeto `COleTemplateServer`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleTemplateServer::ConnectTemplate](#connecttemplate)|Conecta um modelo de documento ao objeto `COleObjectFactory` subjacente.|
|[COleTemplateServer::Unregister](#unregister)|Cancela o registro do modelo de documento associado.|
|[COleTemplateServer:: UpdateRegistry](#updateregistry)|Registra o tipo de documento com o registro do sistema OLE.|

## <a name="remarks"></a>Comentários

Essa classe é derivada da classe [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md); Normalmente, você pode usar `COleTemplateServer` diretamente em vez de derivar sua própria classe. `COleTemplateServer`usa um objeto [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) para gerenciar os documentos do servidor. Use `COleTemplateServer` ao implementar um servidor completo, ou seja, um servidor que pode ser executado como um aplicativo autônomo. Os servidores completos normalmente são aplicativos de interface de vários documentos (MDI), embora haja suporte para aplicativos SDI (interface de documento único). Um `COleTemplateServer` objeto é necessário para cada tipo de documento de servidor que um aplicativo suporta; ou seja, se o aplicativo de servidor oferecer suporte a planilhas e gráficos, `COleTemplateServer` você deverá ter dois objetos.

`COleTemplateServer`Substitui a `OnCreateInstance` função de membro definida `COleObjectFactory`por. Essa função de membro é chamada pelo Framework para criar um C++ objeto do tipo apropriado.

Para obter mais informações sobre servidores, consulte o [artigo servidores: Implementando um](../../mfc/servers-implementing-a-server.md)servidor.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)

`COleTemplateServer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

##  <a name="coletemplateserver"></a>  COleTemplateServer::COleTemplateServer

Constrói um objeto `COleTemplateServer`.

```
COleTemplateServer();
```

### <a name="remarks"></a>Comentários

Para obter uma breve descrição do uso da `COleTemplateServer` classe, consulte a visão geral da classe [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md) .

##  <a name="connecttemplate"></a>  COleTemplateServer::ConnectTemplate

Conecta o modelo de documento apontado por *pDocTemplate* ao objeto [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md) subjacente.

```
void ConnectTemplate(
    REFCLSID clsid,
    CDocTemplate* pDocTemplate,
    BOOL bMultiInstance);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
Referência à ID da classe OLE que o modelo solicita.

*pDocTemplate*<br/>
Ponteiro para o modelo de documento.

*bMultiInstance*<br/>
Indica se uma única instância do aplicativo pode dar suporte a várias instanciações. Se for TRUE, várias instâncias do aplicativo serão iniciadas para cada solicitação para criar um objeto.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [chave de CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

##  <a name="unregister"></a>  COleTemplateServer::Unregister

Cancela o registro do modelo de documento associado.

```
BOOL Unregister();
```

### <a name="return-value"></a>Valor de retorno

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

EnterRemarks

##  <a name="updateregistry"></a>COleTemplateServer:: UpdateRegistry

Carrega informações de tipo de arquivo da cadeia de caracteres de modelo de documento e coloca essas informações no registro do sistema OLE.

```
void UpdateRegistry(
    OLE_APPTYPE nAppType = OAT_INPLACE_SERVER,
    LPCTSTR* rglpszRegister = NULL,
    LPCTSTR* rglpszOverwrite = NULL,
    BOOL bRegister = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nAppType*<br/>
Um valor da enumeração OLE_APPTYPE, que é definido em AFXDISP. T. Ele pode ter qualquer um dos seguintes valores:

- O servidor OAT_INPLACE_SERVER tem a interface de usuário do servidor completo.

- O servidor OAT_SERVER dá suporte apenas à inserção.

- O contêiner OAT_CONTAINER dá suporte a links para objetos inseridos.

- O objeto OAT_DISPATCH_OBJECT `IDispatch`é compatível.

- O servidor OAT_DOC_OBJECT_SERVER dá suporte à incorporação e ao modelo de componente de objeto de documento.

*rglpszRegister*<br/>
Uma lista de entradas gravadas no registro somente se não houver entradas.

*rglpszOverwrite*<br/>
Uma lista de entradas gravadas no registro, independentemente de existirem entradas anteriores.

*bRegister*<br/>
Determina se a classe deve ser registrada. Se *bRegister* for true, a classe será registrada com o registro do sistema. Caso contrário, ele cancelará o registro da classe.

### <a name="remarks"></a>Comentários

As informações de registro são carregadas por meio de uma chamada para [CDocTemplate:: GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). As subcadeias de caracteres recuperadas são identificadas `regFileTypeId`pelos `regFileTypeName`índices, `fileNewName`e, conforme descrito nas `GetDocString` páginas de referência.

Se a `regFileTypeId` subcadeia de caracteres estiver vazia ou se a `GetDocString` chamada falhar por qualquer outro motivo, essa função falhará e as informações do arquivo não serão inseridas no registro.

As informações nos argumentos *rglpszRegister* e *rglpszOverwrite* são gravadas no registro por meio de uma chamada para [AfxOleRegisterServerClass](application-control.md#afxoleregisterserverclass). As informações padrão, que são registradas quando os dois argumentos são nulos, são adequadas para a maioria dos aplicativos. Para obter informações sobre a estrutura das informações nesses argumentos, consulte `AfxOleRegisterServerClass`.

Para obter mais informações, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

## <a name="see-also"></a>Consulte também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)<br/>
[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
