---
title: "Classe de COleServerItem | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "COleServerItem"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleServerItem"
  - "Os aplicativos de servidor VELHOS, gerenciando documentos de servidor"
  - "Os aplicativos de servidor VELHOS, interfaces do servidor"
  - "Documentos VELHOS de servidor"
  - "servidores, O OLE"
ms.assetid: 80256df6-3888-4256-944b-787d4b2e6b0d
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleServerItem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a interface do servidor para itens VELHOS.  
  
## Sintaxe  
  
```  
class COleServerItem : public CDocItem  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleServerItem::COleServerItem](../Topic/COleServerItem::COleServerItem.md)|Constrói um objeto de `COleServerItem` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleServerItem::AddOtherClipboardData](../Topic/COleServerItem::AddOtherClipboardData.md)|Os formatos de apresentação e a conversão de locais em `COleDataSource` objeto.|  
|[COleServerItem::CopyToClipboard](../Topic/COleServerItem::CopyToClipboard.md)|Copia o item na área de transferência.|  
|[COleServerItem::DoDragDrop](../Topic/COleServerItem::DoDragDrop.md)|Executa uma operação de arrastar e soltar.|  
|[COleServerItem::GetClipboardData](../Topic/COleServerItem::GetClipboardData.md)|Obtém a fonte de dados para uso na transferência de dados \(arrastar e soltar ou área de transferência\).|  
|[COleServerItem::GetDocument](../Topic/COleServerItem::GetDocument.md)|Retorna o documento de servidor que contém o item.|  
|[COleServerItem::GetEmbedSourceData](../Topic/COleServerItem::GetEmbedSourceData.md)|Obtém os dados de **CF\_EMBEDSOURCE** para um item OLE.|  
|[COleServerItem::GetItemName](../Topic/COleServerItem::GetItemName.md)|Retorna o nome do item.  Usado para itens associados apenas.|  
|[COleServerItem::GetLinkSourceData](../Topic/COleServerItem::GetLinkSourceData.md)|Obtém os dados de `CF_LINKSOURCE` para um item OLE.|  
|[COleServerItem::GetObjectDescriptorData](../Topic/COleServerItem::GetObjectDescriptorData.md)|Obtém os dados de **CF\_OBJECTDESCRIPTOR** para um item OLE.|  
|[COleServerItem::IsConnected](../Topic/COleServerItem::IsConnected.md)|Indica se o item está conectado atualmente em um contêiner ativo.|  
|[COleServerItem::IsLinkedItem](../Topic/COleServerItem::IsLinkedItem.md)|Indica se o item representa um item OLE associado.|  
|[COleServerItem::NotifyChanged](../Topic/COleServerItem::NotifyChanged.md)|Atualizar todos os recipientes com atualização automática de link.|  
|[COleServerItem::OnDoVerb](../Topic/COleServerItem::OnDoVerb.md)|Chamado para executar um comando.|  
|[COleServerItem::OnDraw](../Topic/COleServerItem::OnDraw.md)|Chamado quando as solicitações de contêiner desenhar o item; implementação necessária.|  
|[COleServerItem::OnDrawEx](../Topic/COleServerItem::OnDrawEx.md)|Chamado para o desenho especializada do item.|  
|[COleServerItem::OnGetClipboardData](../Topic/COleServerItem::OnGetClipboardData.md)|Chamado pela estrutura para obter os dados que poderiam ser copiados para a área de transferência.|  
|[COleServerItem::OnGetExtent](../Topic/COleServerItem::OnGetExtent.md)|Chamado pela estrutura para recuperar o tamanho do item OLE.|  
|[COleServerItem::OnInitFromData](../Topic/COleServerItem::OnInitFromData.md)|Chamado pela estrutura para inicializar um item usando OLE o conteúdo do objeto de transferência de dados especificado.|  
|[COleServerItem::OnQueryUpdateItems](../Topic/COleServerItem::OnQueryUpdateItems.md)|Chamado para determinar se qualquer item associado requer atualizar.|  
|[COleServerItem::OnRenderData](../Topic/COleServerItem::OnRenderData.md)|Recupera dados como parte de renderização tarde.|  
|[COleServerItem::OnRenderFileData](../Topic/COleServerItem::OnRenderFileData.md)|Recupera dados em um objeto de `CFile` como parte de renderização tarde.|  
|[COleServerItem::OnRenderGlobalData](../Topic/COleServerItem::OnRenderGlobalData.md)|Recupera dados em `HGLOBAL` como parte de renderização tarde.|  
|[COleServerItem::OnSetColorScheme](../Topic/COleServerItem::OnSetColorScheme.md)|Chamado para definir o esquema de cores de item.|  
|[COleServerItem::OnSetData](../Topic/COleServerItem::OnSetData.md)|Chamado para definir os dados do item.|  
|[COleServerItem::OnSetExtent](../Topic/COleServerItem::OnSetExtent.md)|Chamado pela estrutura para definir o tamanho do item OLE.|  
|[COleServerItem::OnUpdate](../Topic/COleServerItem::OnUpdate.md)|Quando chamado alguma parte do documento o item pertence na é alterado.|  
|[COleServerItem::OnUpdateItems](../Topic/COleServerItem::OnUpdateItems.md)|Chamado para atualizar o cache de apresentação de todos os itens no documento do servidor.|  
|[COleServerItem::SetItemName](../Topic/COleServerItem::SetItemName.md)|Define o nome do item.  Usado para itens associados apenas.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleServerItem::GetDataSource](../Topic/COleServerItem::GetDataSource.md)|Obtém o objeto usado para formatos de conversão do armazenamento.|  
|[COleServerItem::OnHide](../Topic/COleServerItem::OnHide.md)|Chamado pela estrutura para ocultar o item OLE.|  
|[COleServerItem::OnOpen](../Topic/COleServerItem::OnOpen.md)|Chamado pela estrutura para exibir o item OLE em sua própria janela de nível superior.|  
|[COleServerItem::OnShow](../Topic/COleServerItem::OnShow.md)|Chamado quando as solicitações de contêiner mostrar o item.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleServerItem::m\_sizeExtent](../Topic/COleServerItem::m_sizeExtent.md)|Informa o servidor sobre quanto de item OLE é visível.|  
  
## Comentários  
 Um item associado pode representar qualquer ou qualquer documento de servidor.  Um item inserido sempre representa um documento inteiro do servidor.  
  
 A classe de `COleServerItem` define várias funções de membro substituíveis que são chamados pelas bibliotecas de vínculo dinâmico VELHOS \(DLLs\) do sistema, geralmente em resposta às solicitações de aplicativo do contêiner.  Essas funções de membro permitem que o aplicativo de contêiner manipular indiretamente o item de várias maneiras, como exibi\-lo, executar os verbos, ou recuperar os dados em vários formatos.  
  
 Para usar `COleServerItem`, derive uma classe de ele e implementar as funções de membro de [OnDraw](../Topic/COleServerItem::OnDraw.md) e de [Serialize](../Topic/CObject::Serialize.md) .  A função de `OnDraw` fornece a representação de metarquivo de um item, permitindo que é exibido quando um aplicativo de contêiner abrir um documento composto.  A função de `Serialize` de `CObject` fornece a representação nativo de um item, permitindo que um item inserido é transferido entre o servidor e aplicativos de contêiner.  [OnGetExtent](../Topic/COleServerItem::OnGetExtent.md) fornece o tamanho natural de item para o recipiente, ativando o recipiente para dimensionar o item.  
  
 Para obter mais informações sobre servidores e os tópicos relacionados, consulte o artigo [servidores: implementando um servidor](../../mfc/servers-implementing-a-server.md) e “criação de um contêiner\/aplicativo para servidores no artigo” [Recipientes: recursos avançados](../../mfc/containers-advanced-features.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 `COleServerItem`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [O MFC exemplos HIERSVR](../../top/visual-cpp-samples.md)   
 [Classe de CDocItem](../../mfc/reference/cdocitem-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Classe de COleServerDoc](../Topic/COleServerDoc%20Class.md)   
 [Classe de COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)