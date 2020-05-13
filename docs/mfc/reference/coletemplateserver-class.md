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
ms.openlocfilehash: 561da5060aae3c938dc3e55d0310718a881c1a3b
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753733"
---
# <a name="coletemplateserver-class"></a>Classe COleTemplateServer

Usado para servidores de edição visual OLE, servidores de automação e contêineres de link (aplicativos que suportam links para incorporações).

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
|[COleTemplateServer::ConnectTemplate](#connecttemplate)|Conecta um modelo de documento `COleObjectFactory` ao objeto subjacente.|
|[COleTemplateServer::Unregister](#unregister)|Não registra o modelo de documento associado.|
|[COleTemplateServer::Registro de atualização](#updateregistry)|Registra o tipo de documento no registro do sistema OLE.|

## <a name="remarks"></a>Comentários

Esta classe é derivada da classe [COleObjectFactory;](../../mfc/reference/coleobjectfactory-class.md) geralmente, você `COleTemplateServer` pode usar diretamente em vez de derivar sua própria classe. `COleTemplateServer`usa um objeto [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) para gerenciar os documentos do servidor. Use `COleTemplateServer` ao implementar um servidor completo, ou seja, um servidor que pode ser executado como um aplicativo autônomo. Servidores completos são normalmente aplicativos de interface de documento múltiplo (MDI), embora aplicativos de interface de documento único (SDI) sejam suportados. Um `COleTemplateServer` objeto é necessário para cada tipo de documento de servidor que um aplicativo suporta; ou seja, se o aplicativo do servidor suportar planilhas `COleTemplateServer` e gráficos, você deve ter dois objetos.

`COleTemplateServer`substitui a `OnCreateInstance` função de `COleObjectFactory`membro definida por . Esta função de membro é chamada pela estrutura para criar um objeto C++ do tipo adequado.

Para obter mais informações sobre servidores, consulte o artigo [Servidores: Implementando um Servidor](../../mfc/servers-implementing-a-server.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Coleobjectfactory](../../mfc/reference/coleobjectfactory-class.md)

`COleTemplateServer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="coletemplateservercoletemplateserver"></a><a name="coletemplateserver"></a>COleTemplateServer::COleTemplateServer

Constrói um objeto `COleTemplateServer`.

```
COleTemplateServer();
```

### <a name="remarks"></a>Comentários

Para obter uma breve descrição `COleTemplateServer` do uso da classe, consulte a visão geral da classe [COleLinkingDoc.](../../mfc/reference/colelinkingdoc-class.md)

## <a name="coletemplateserverconnecttemplate"></a><a name="connecttemplate"></a>COleTemplateServer::ConnectTemplate

Conecta o modelo de documento apontado pelo *pDocTemplate* ao objeto [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md) subjacente.

```cpp
void ConnectTemplate(
    REFCLSID clsid,
    CDocTemplate* pDocTemplate,
    BOOL bMultiInstance);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
Referência ao ID de classe OLE que o modelo solicita.

*pDocTemplate*<br/>
Ponteiro para o modelo do documento.

*bMultiInstance*<br/>
Indica se uma única instância do aplicativo pode suportar múltiplas instanciações. Se TRUE, várias instâncias do aplicativo são lançadas para cada solicitação criar um objeto.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [a tecla CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

## <a name="coletemplateserverunregister"></a><a name="unregister"></a>COleTemplateServer::Unregister

Não registra o modelo de documento associado.

```
BOOL Unregister();
```

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

EnterComentários

## <a name="coletemplateserverupdateregistry"></a><a name="updateregistry"></a>COleTemplateServer::Registro de atualização

Carrega informações do tipo de arquivo da seqüência de modelode documento e coloca essas informações no registro do sistema OLE.

```cpp
void UpdateRegistry(
    OLE_APPTYPE nAppType = OAT_INPLACE_SERVER,
    LPCTSTR* rglpszRegister = NULL,
    LPCTSTR* rglpszOverwrite = NULL,
    BOOL bRegister = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nAppType*<br/>
Um valor da enumeração OLE_APPTYPE, que é definido em AFXDISP. H. Ele pode ter qualquer um dos seguintes valores:

- OAT_INPLACE_SERVER Server tem interface de usuário de servidor completo.

- OAT_SERVER servidor suporta apenas incorporação.

- OAT_CONTAINER Container suporta links para objetos incorporados.

- OAT_DISPATCH_OBJECT Objeto `IDispatch`é capaz.

- OAT_DOC_OBJECT_SERVER servidor suporta incorporação e o modelo de componente Objeto de documento.

*rglpszRegister*<br/>
Uma lista de entradas que é escrita no registro somente se não houver entradas.

*rglpszOverwrite*<br/>
Uma lista de entradas que está escrita no registro, independentemente de existirem quaisquer entradas anteriores.

*Bregister*<br/>
Determina se a classe deve ser registrada. Se *bRegister* for TRUE, a classe será registrada no registro do sistema. Caso contrário, ele desregistra a classe.

### <a name="remarks"></a>Comentários

As informações de registro são carregadas por meio de uma chamada para [CDocTemplate::GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). As subcordas recuperadas são aquelas identificadas `regFileTypeName`pelos `fileNewName`índices `GetDocString` `regFileTypeId`e, como descrito nas páginas de referência.

Se `regFileTypeId` a substring estiver vazia `GetDocString` ou se a chamada falhar por qualquer outro motivo, essa função falhará e as informações do arquivo não são inseridas no registro.

As informações nos argumentos *rglpszRegister* e *rglpszOverwrite* são escritas no registro através de uma chamada para [AfxOleRegisterServerClass](application-control.md#afxoleregisterserverclass). As informações padrão, que são registradas quando os dois argumentos são NULAS, são adequadas para a maioria dos aplicativos. Para obter informações sobre a estrutura das `AfxOleRegisterServerClass`informações nesses argumentos, consulte .

Para obter mais informações, consulte [Implementando a interface iDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Classe COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)<br/>
[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
