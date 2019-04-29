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
ms.openlocfilehash: 3abdf1dc2da5ef9a111371b501d5cd8ce208825d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62373547"
---
# <a name="coletemplateserver-class"></a>Classe COleTemplateServer

Usado para servidores, servidores de automação e contêineres (aplicativos que dão suporte a links para incorporações) do link de edição visual do OLE.

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
|[COleTemplateServer::ConnectTemplate](#connecttemplate)|Se conecta a um modelo de documento subjacente `COleObjectFactory` objeto.|
|[COleTemplateServer::Unregister](#unregister)|Cancela o registro de modelo de documento associado.|
|[COleTemplateServer::UpdateRegistry](#updateregistry)|Registra o tipo de documento com o registro do sistema OLE.|

## <a name="remarks"></a>Comentários

Essa classe é derivada da classe [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md); normalmente, você pode usar `COleTemplateServer` diretamente, em vez de derivar sua própria classe. `COleTemplateServer` usa um [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto para gerenciar os documentos de servidor. Use `COleTemplateServer` ao implementar um servidor completo, ou seja, um servidor que pode ser executado como um aplicativo autônomo. Servidores completos geralmente são vários aplicativos MDI (interface MDI) de documento, embora haja suporte para os aplicativos de interface (SDI) único documento. Uma `COleTemplateServer` objeto é necessário para cada tipo de documento do servidor oferece suporte a um aplicativo; ou seja, se seu aplicativo de servidor dá suporte a planilhas e gráficos, você deve ter dois `COleTemplateServer` objetos.

`COleTemplateServer` substitui o `OnCreateInstance` função de membro definida pelo `COleObjectFactory`. Essa função membro é chamada pelo framework para criar um objeto de C++ do tipo adequado.

Para obter mais informações sobre servidores, consulte o artigo [servidores: Implementação de um servidor](../../mfc/servers-implementing-a-server.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)

`COleTemplateServer`

## <a name="requirements"></a>Requisitos

**Header:** afxdisp.h

##  <a name="coletemplateserver"></a>  COleTemplateServer::COleTemplateServer

Constrói um objeto `COleTemplateServer`.

```
COleTemplateServer();
```

### <a name="remarks"></a>Comentários

Para obter uma descrição breve do uso do `COleTemplateServer` classe, consulte a [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md) visão geral da classe.

##  <a name="connecttemplate"></a>  COleTemplateServer::ConnectTemplate

Conecta-se o modelo de documento apontado por *pDocTemplate* subjacente [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md) objeto.

```
void ConnectTemplate(
    REFCLSID clsid,
    CDocTemplate* pDocTemplate,
    BOOL bMultiInstance);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
Referência para a ID de classe OLE que solicita o modelo.

*pDocTemplate*<br/>
Ponteiro para o modelo de documento.

*bMultiInstance*<br/>
Indica se uma única instância do aplicativo pode dar suporte a várias instâncias. Se for TRUE, várias instâncias do aplicativo são iniciadas para cada solicitação criar um objeto.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [chave CLSID](/windows/desktop/com/clsid-key-hklm) no SDK do Windows.

##  <a name="unregister"></a>  COleTemplateServer::Unregister

Cancela o registro de modelo de documento associado.

```
BOOL Unregister();
```

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

EnterRemarks

##  <a name="updateregistry"></a>  COleTemplateServer::UpdateRegistry

Carrega informações de tipo de arquivo da cadeia de caracteres de modelo de documento e colocará essas informações no registro do sistema OLE.

```
void UpdateRegistry(
    OLE_APPTYPE nAppType = OAT_INPLACE_SERVER,
    LPCTSTR* rglpszRegister = NULL,
    LPCTSTR* rglpszOverwrite = NULL,
    BOOL bRegister = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nAppType*<br/>
Um valor de enumeração OLE_APPTYPE, que é definido no AFXDISP. H. Ele pode ter qualquer um dos seguintes valores:

- Servidor OAT_INPLACE_SERVER tem interface do usuário completo do servidor.

- OAT_SERVER Server dá suporte à inserção de apenas.

- Contêiner OAT_CONTAINER dá suporte a links para os objetos inseridos.

- Objeto OAT_DISPATCH_OBJECT é `IDispatch`-capaz.

- Servidor OAT_DOC_OBJECT_SERVER dá suporte à inserção e o modelo de componente do objeto de documento.

*rglpszRegister*<br/>
Uma lista de entradas será gravada no registro somente se não existe nenhuma entrada.

*rglpszOverwrite*<br/>
Uma lista de entradas que é gravada no registro, independentemente de existirem quaisquer entradas anteriores.

*bRegister*<br/>
Determina se a classe deve ser registrado. Se *bRegistre-se participar* for TRUE, a classe é registrada com o registro do sistema. Caso contrário, ele cancela o registro da classe.

### <a name="remarks"></a>Comentários

As informações de registro são carregadas por meio de uma chamada para [CDocTemplate::GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). As subcadeias de caracteres recuperadas são aquelas identificadas pelos índices `regFileTypeId`, `regFileTypeName`, e `fileNewName`, conforme descrito no `GetDocString` as páginas de referência.

Se o `regFileTypeId` subcadeia de caracteres está vazia ou se a chamada para `GetDocString` falhar por qualquer outro motivo, essa função falhará e as informações do arquivo não são inseridas no registro.

As informações nos argumentos *rglpszRegister* e *rglpszOverwrite* é gravado no registro por meio de uma chamada para [AfxOleRegisterServerClass](application-control.md#afxoleregisterserverclass). As informações padrão que são registradas quando os dois argumentos forem nulos, são adequadas para a maioria dos aplicativos. Para obter informações sobre a estrutura das informações nesses argumentos, consulte `AfxOleRegisterServerClass`.

Para obter mais informações, consulte [Implementando a IDispatch Interface](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

## <a name="see-also"></a>Consulte também

[Exemplo MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Classe COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)<br/>
[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
