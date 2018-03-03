---
title: Classe COleTemplateServer | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleTemplateServer
- AFXDISP/COleTemplateServer
- AFXDISP/COleTemplateServer::COleTemplateServer
- AFXDISP/COleTemplateServer::ConnectTemplate
- AFXDISP/COleTemplateServer::Unregister
- AFXDISP/COleTemplateServer::UpdateRegistry
dev_langs:
- C++
helpviewer_keywords:
- COleTemplateServer [MFC], COleTemplateServer
- COleTemplateServer [MFC], ConnectTemplate
- COleTemplateServer [MFC], Unregister
- COleTemplateServer [MFC], UpdateRegistry
ms.assetid: 47a2887d-8162-4993-a842-a784177c7f5c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d4bf5f696eeff3e4e26a9d77714c0d5a6f093aaa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="coletemplateserver-class"></a>Classe COleTemplateServer
Usado para OLE visual de edição de servidores, servidores de automação e contêineres de link (aplicativos que oferecem suporte a links para incorporações).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleTemplateServer : public COleObjectFactory  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleTemplateServer::COleTemplateServer](#coletemplateserver)|Constrói um objeto `COleTemplateServer`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleTemplateServer::ConnectTemplate](#connecttemplate)|Se conecta a um modelo de documento para o subjacente `COleObjectFactory` objeto.|  
|[COleTemplateServer::Unregister](#unregister)|Cancela o registro do modelo de documento associado.|  
|[COleTemplateServer::UpdateRegistry](#updateregistry)|Registra o tipo de documento com o registro do sistema OLE.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é derivada da classe [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md); normalmente, você pode usar `COleTemplateServer` diretamente, em vez de derivação de sua própria classe. `COleTemplateServer`usa um [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto para gerenciar os documentos de servidor. Use `COleTemplateServer` durante a implementação de um servidor completo, ou seja, um servidor que pode ser executado como um aplicativo autônomo. Servidores completos geralmente são vários aplicativos de interface (MDI) do documento, embora haja suporte para os aplicativos de interface (SDI) único documento. Um `COleTemplateServer` objeto é necessária para cada tipo de documento do servidor oferece suporte a um aplicativo; ou seja, se seu aplicativo de servidor dá suporte a planilhas e gráficos, você deve ter dois `COleTemplateServer` objetos.  
  
 `COleTemplateServer`substitui o `OnCreateInstance` função de membro definida pelo `COleObjectFactory`. Essa função de membro é chamada pelo framework para criar um objeto C++ do tipo correto.  
  
 Para obter mais informações sobre servidores, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)  
  
 `COleTemplateServer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="coletemplateserver"></a>COleTemplateServer::COleTemplateServer  
 Constrói um objeto `COleTemplateServer`.  
  
```  
COleTemplateServer();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter uma descrição breve do uso de `COleTemplateServer` de classe, consulte o [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md) visão geral da classe.  
  
##  <a name="connecttemplate"></a>COleTemplateServer::ConnectTemplate  
 Conecta-se o modelo de documento apontado pelo `pDocTemplate` para subjacente [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md) objeto.  
  
```  
void ConnectTemplate(
    REFCLSID clsid,  
    CDocTemplate* pDocTemplate,  
    BOOL bMultiInstance);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 Referência à ID de classe OLE que solicita o modelo.  
  
 `pDocTemplate`  
 Ponteiro para o modelo de documento.  
  
 `bMultiInstance`  
 Indica se uma única instância do aplicativo pode dar suporte a várias instâncias. Se **TRUE**, várias instâncias do aplicativo são iniciadas para cada solicitação para criar um objeto.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no SDK do Windows.  
  
##  <a name="unregister"></a>COleTemplateServer::Unregister  
 Cancela o registro do modelo de documento associado.  
  
```  
BOOL Unregister();
```  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se bem-sucedido; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 EnterRemarks  
  
##  <a name="updateregistry"></a>COleTemplateServer::UpdateRegistry  
 Carrega informações de tipo de arquivo de cadeia de caracteres de modelo de documento e coloca essas informações no registro do sistema OLE.  
  
```  
void UpdateRegistry(
    OLE_APPTYPE nAppType = OAT_INPLACE_SERVER,  
    LPCTSTR* rglpszRegister = NULL,  
    LPCTSTR* rglpszOverwrite = NULL,  
    BOOL bRegister = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nAppType`  
 Um valor da **OLE_APPTYPE** enumeração, que é definida em AFXDISP. H. Ele pode ter qualquer um dos seguintes valores:  
  
- `OAT_INPLACE_SERVER`Servidor tem uma interface de usuário do servidor completo.  
  
- `OAT_SERVER`Servidor dá suporte apenas a inserção.  
  
- `OAT_CONTAINER`Contêiner oferece suporte a links para objetos inseridos.  
  
- `OAT_DISPATCH_OBJECT`Objeto `IDispatch`-compatível com.  
  
- **OAT_DOC_OBJECT_SERVER** Server oferece suporte a incorporação e o modelo de componente do objeto de documento.  
  
 `rglpszRegister`  
 Uma lista de entradas que é gravada no registro somente se não existe nenhuma entrada.  
  
 `rglpszOverwrite`  
 Uma lista de entradas que será gravada no registro independentemente de existirem todas as entradas anteriores.  
  
 `bRegister`  
 Determina se a classe deve ser registrado. Se `bRegister` é **TRUE**, a classe é registrada com o registro do sistema. Caso contrário, ele cancela o registro de classe.  
  
### <a name="remarks"></a>Comentários  
 As informações de registro são carregadas por meio de uma chamada para [CDocTemplate::GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). As subcadeias de caracteres recuperadas são identificadas pelos índices **regFileTypeId**, **regFileTypeName**, e **fileNewName**, conforme descrito no `GetDocString` páginas de referência.  
  
 Se o **regFileTypeId** subcadeia de caracteres está vazia ou se a chamada para `GetDocString` falhar por qualquer outro motivo, essa função falhará e as informações do arquivo não são inseridas no registro.  
  
 As informações nos argumentos `rglpszRegister` e `rglpszOverwrite` é gravado no registro por meio de uma chamada para [AfxOleRegisterServerClass](application-control.md#afxoleregisterserverclass). As informações padrão, que são registradas quando os dois argumentos são **nulo**, é adequado para a maioria dos aplicativos. Para obter informações sobre a estrutura das informações nesses argumentos, consulte `AfxOleRegisterServerClass`.  
  
 Para obter mais informações, consulte [Implementando a IDispatch Interface](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)   
 [Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
