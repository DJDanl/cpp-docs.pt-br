---
title: "Classe de COleClientItem | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "COleClientItem"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "itens de cliente e contêiner VELHOS"
  - "Classe de COleClientItem"
  - "classe de interface de contêiner"
  - "Classe OLE de item do cliente"
  - "Contêiner VELHOS, itens de cliente"
  - "Contêiner VELHOS, classe de interface"
ms.assetid: 7f571b7c-2758-4839-847a-0cf1ef643128
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleClientItem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define a interface recipiente para itens VELHOS.  
  
## Sintaxe  
  
```  
class COleClientItem : public CDocItem  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleClientItem::COleClientItem](../Topic/COleClientItem::COleClientItem.md)|Constrói um objeto de `COleClientItem` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleClientItem::Activate](../Topic/COleClientItem::Activate.md)|Abra o item para OLE uma operação e executa no verbo especificado.|  
|[COleClientItem::ActivateAs](../Topic/COleClientItem::ActivateAs.md)|Alterna o item como outro tipo.|  
|[COleClientItem::AttachDataObject](../Topic/COleClientItem::AttachDataObject.md)|Acessa os dados no objeto OLE.|  
|[COleClientItem::CanCreateFromData](../Topic/COleClientItem::CanCreateFromData.md)|Indica se um aplicativo de contêiner pode criar um objeto inserido.|  
|[COleClientItem::CanCreateLinkFromData](../Topic/COleClientItem::CanCreateLinkFromData.md)|Indica se um aplicativo de contêiner pode criar um objeto associado.|  
|[COleClientItem::CanPaste](../Topic/COleClientItem::CanPaste.md)|Indica se a área de transferência contém um item OLE embeddable ou estático.|  
|[COleClientItem::CanPasteLink](../Topic/COleClientItem::CanPasteLink.md)|Indica se a área de transferência contém um item OLE enlaçável.|  
|[COleClientItem::Close](../Topic/COleClientItem::Close.md)|Fecha um link a um servidor mas não destrói o item OLE.|  
|[COleClientItem::ConvertTo](../Topic/COleClientItem::ConvertTo.md)|Converte o item para outro tipo.|  
|[COleClientItem::CopyToClipboard](../Topic/COleClientItem::CopyToClipboard.md)|Copia o item OLE para a área de transferência.|  
|[COleClientItem::CreateCloneFrom](../Topic/COleClientItem::CreateCloneFrom.md)|Cria uma cópia de um item existente.|  
|[COleClientItem::CreateFromClipboard](../Topic/COleClientItem::CreateFromClipboard.md)|Cria um item inserido da área de transferência.|  
|[COleClientItem::CreateFromData](../Topic/COleClientItem::CreateFromData.md)|Cria um item inserido de um objeto de dados.|  
|[COleClientItem::CreateFromFile](../Topic/COleClientItem::CreateFromFile.md)|Cria um item inserido de um arquivo.|  
|[COleClientItem::CreateLinkFromClipboard](../Topic/COleClientItem::CreateLinkFromClipboard.md)|Cria um item associado da área de transferência.|  
|[COleClientItem::CreateLinkFromData](../Topic/COleClientItem::CreateLinkFromData.md)|Cria um item associado de um objeto de dados.|  
|[COleClientItem::CreateLinkFromFile](../Topic/COleClientItem::CreateLinkFromFile.md)|Cria um item associado de um arquivo.|  
|[COleClientItem::CreateNewItem](../Topic/COleClientItem::CreateNewItem.md)|Cria um novo item inserido iniciando o aplicativo para servidores.|  
|[COleClientItem::CreateStaticFromClipboard](../Topic/COleClientItem::CreateStaticFromClipboard.md)|Cria um item estático da área de transferência.|  
|[COleClientItem::CreateStaticFromData](../Topic/COleClientItem::CreateStaticFromData.md)|Cria um item estático de um objeto de dados.|  
|[COleClientItem::Deactivate](../Topic/COleClientItem::Deactivate.md)|Desativa o item.|  
|[COleClientItem::DeactivateUI](../Topic/COleClientItem::DeactivateUI.md)|Restaura a interface do usuário do aplicativo de contêiner para seu estado original.|  
|[COleClientItem::Delete](../Topic/COleClientItem::Delete.md)|Exclui ou desliga o item OLE se fosse um item associado.|  
|[COleClientItem::DoDragDrop](../Topic/COleClientItem::DoDragDrop.md)|Executa uma operação de arrastar e soltar.|  
|[COleClientItem::DoVerb](../Topic/COleClientItem::DoVerb.md)|Executa o verbo especificado.|  
|[COleClientItem::Draw](../Topic/COleClientItem::Draw.md)|Desenha o item OLE.|  
|[COleClientItem::GetActiveView](../Topic/COleClientItem::GetActiveView.md)|Obtém a exibição em que o item é ativado no lugar.|  
|[COleClientItem::GetCachedExtent](../Topic/COleClientItem::GetCachedExtent.md)|Retorna os limites do retângulo OLE de item.|  
|[COleClientItem::GetClassID](../Topic/COleClientItem::GetClassID.md)|Obtém a identificação de classe do item atual|  
|[COleClientItem::GetClipboardData](../Topic/COleClientItem::GetClipboardData.md)|Obtém os dados que devem ser colocados na área de transferência chamar a função de membro de `CopyToClipboard` .|  
|[COleClientItem::GetDocument](../Topic/COleClientItem::GetDocument.md)|Retorna o objeto de `COleDocument` que contém o item atual.|  
|[COleClientItem::GetDrawAspect](../Topic/COleClientItem::GetDrawAspect.md)|Obtém a exibição atual de item para renderização.|  
|[COleClientItem::GetExtent](../Topic/COleClientItem::GetExtent.md)|Retorna os limites do retângulo OLE de item.|  
|[COleClientItem::GetIconFromRegistry](../Topic/COleClientItem::GetIconFromRegistry.md)|Retrives um identificador para um ícone associado com o servidor de um determinado CLSID.|  
|[COleClientItem::GetIconicMetafile](../Topic/COleClientItem::GetIconicMetafile.md)|Obtém o metarquivo usado desenhando o ícone de item.|  
|[COleClientItem::GetInPlaceWindow](../Topic/COleClientItem::GetInPlaceWindow.md)|Retorna um ponteiro para a janela de edição in\-loco de item.|  
|[COleClientItem::GetItemState](../Topic/COleClientItem::GetItemState.md)|Obtém o estado atual do item.|  
|[COleClientItem::GetLastStatus](../Topic/COleClientItem::GetLastStatus.md)|Retorna o status da operação OLE a última vez.|  
|[COleClientItem::GetLinkUpdateOptions](../Topic/COleClientItem::GetLinkUpdateOptions.md)|Retorna o modo de atualização para um item associado \(recurso avançado\).|  
|[COleClientItem::GetType](../Topic/COleClientItem::GetType.md)|Retorna o tipo \(inserido, ou\) associado estático de item OLE.|  
|[COleClientItem::GetUserType](../Topic/COleClientItem::GetUserType.md)|Obtém uma cadeia de caracteres que descreve o tipo de item.|  
|[COleClientItem::IsInPlaceActive](../Topic/COleClientItem::IsInPlaceActive.md)|Retorna `TRUE` se o item está no lugar.|  
|[COleClientItem::IsLinkUpToDate](../Topic/COleClientItem::IsLinkUpToDate.md)|Retorna **Verdadeiro** se um item associado é atualizado com seu documento de origem.|  
|[COleClientItem::IsModified](../Topic/COleClientItem::IsModified.md)|Retorna `TRUE` se o item foi alterado desde que foi o exceto o último.|  
|[COleClientItem::IsOpen](../Topic/COleClientItem::IsOpen.md)|Retorna `TRUE` se o item está atualmente aberto no aplicativo para servidores.|  
|[COleClientItem::IsRunning](../Topic/COleClientItem::IsRunning.md)|Retorna `TRUE` se o aplicativo para servidores de item está sendo executado.|  
|[COleClientItem::OnActivate](../Topic/COleClientItem::OnActivate.md)|Chamado pela estrutura para notificar o item que está ativado.|  
|[COleClientItem::OnActivateUI](../Topic/COleClientItem::OnActivateUI.md)|Chamado pela estrutura para notificar o item que está ativada e deve mostrar sua interface do usuário.|  
|[COleClientItem::OnChange](../Topic/COleClientItem::OnChange.md)|Chamado quando o servidor modificar o item OLE.  Implementação necessária.|  
|[COleClientItem::OnDeactivate](../Topic/COleClientItem::OnDeactivate.md)|Chamado pela estrutura quando um item é desativado.|  
|[COleClientItem::OnDeactivateUI](../Topic/COleClientItem::OnDeactivateUI.md)|Chamado pela estrutura quando o servidor remova sua interface do usuário no lugar.|  
|[COleClientItem::OnGetClipboardData](../Topic/COleClientItem::OnGetClipboardData.md)|Chamado pela estrutura para obter os dados a serem copiados para a área de transferência.|  
|[COleClientItem::OnInsertMenus](../Topic/COleClientItem::OnInsertMenus.md)|Chamado pela estrutura para criar um menu composto.|  
|[COleClientItem::OnRemoveMenus](../Topic/COleClientItem::OnRemoveMenus.md)|Chamado pela estrutura para remover os menus do contêiner de um menu composto.|  
|[COleClientItem::OnSetMenu](../Topic/COleClientItem::OnSetMenu.md)|Chamado pela estrutura do para instalar e remover um menu composto.|  
|[COleClientItem::OnShowControlBars](../Topic/COleClientItem::OnShowControlBars.md)|Chamado pela estrutura para exibir e ocultar barras de controle.|  
|[COleClientItem::OnUpdateFrameTitle](../Topic/COleClientItem::OnUpdateFrameTitle.md)|Chamado pela estrutura para atualizar a barra de título da janela do quadro.|  
|[COleClientItem::ReactivateAndUndo](../Topic/COleClientItem::ReactivateAndUndo.md)|Reactivates o item e desfaz a operação da última de edição in\-loco.|  
|[COleClientItem::Release](../Topic/COleClientItem::Release.md)|Libera a conexão a um item associado OLE e fechá\-lo estiver aberta.  Não destrói o item de cliente.|  
|[COleClientItem::Reload](../Topic/COleClientItem::Reload.md)|Recarrega o item após uma chamada a `ActivateAs`.|  
|[COleClientItem::Run](../Topic/COleClientItem::Run.md)|Executa o aplicativo associado com o item.|  
|[COleClientItem::SetDrawAspect](../Topic/COleClientItem::SetDrawAspect.md)|Define a exibição atual de item para renderização.|  
|[COleClientItem::SetExtent](../Topic/COleClientItem::SetExtent.md)|Define o retângulo delimitador do item OLE.|  
|[COleClientItem::SetHostNames](../Topic/COleClientItem::SetHostNames.md)|Defina os nomes que o servidor exibe ao editar o item OLE.|  
|[COleClientItem::SetIconicMetafile](../Topic/COleClientItem::SetIconicMetafile.md)|Armazenar em cache o metarquivo usado desenhando o ícone de item.|  
|[COleClientItem::SetItemRects](../Topic/COleClientItem::SetItemRects.md)|Define o retângulo delimitador do item.|  
|[COleClientItem::SetLinkUpdateOptions](../Topic/COleClientItem::SetLinkUpdateOptions.md)|Defina o modo de atualização para um item associado \(recurso avançado\).|  
|[COleClientItem::SetPrintDevice](../Topic/COleClientItem::SetPrintDevice.md)|Define o dispositivo de destino PRINT\- para este item de cliente.|  
|[COleClientItem::UpdateLink](../Topic/COleClientItem::UpdateLink.md)|Atualiza o cache de apresentação de um item.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleClientItem::CanActivate](../Topic/COleClientItem::CanActivate.md)|Chamado pela estrutura para determinar se o ativação in\-loco é permitido.|  
|[COleClientItem::OnChangeItemPosition](../Topic/COleClientItem::OnChangeItemPosition.md)|Chamado pela estrutura quando a posição de um item alterar.|  
|[COleClientItem::OnDeactivateAndUndo](../Topic/COleClientItem::OnDeactivateAndUndo.md)|Chamado pela estrutura para desfazer após a ativação.|  
|[COleClientItem::OnDiscardUndoState](../Topic/COleClientItem::OnDiscardUndoState.md)|Chamado pela estrutura para descartar o item desfazer informações de estado.|  
|[COleClientItem::OnGetClipRect](../Topic/COleClientItem::OnGetClipRect.md)|Chamado pela estrutura para obter recorte\- o retângulo de item coordena.|  
|[COleClientItem::OnGetItemPosition](../Topic/COleClientItem::OnGetItemPosition.md)|Chamado pela estrutura para obter a posição do item relativo para o modo de exibição.|  
|[COleClientItem::OnGetWindowContext](../Topic/COleClientItem::OnGetWindowContext.md)|Chamado pela estrutura quando um item é ativado no lugar.|  
|[COleClientItem::OnScrollBy](../Topic/COleClientItem::OnScrollBy.md)|Chamado pela estrutura para rolar o item no modo.|  
|[COleClientItem::OnShowItem](../Topic/COleClientItem::OnShowItem.md)|Chamado pela estrutura para exibir o item OLE.|  
  
## Comentários  
 Um item OLE representa os dados, criados e mantidos por um aplicativo para servidores, que perfeitamente” “pode ser inserido em um documento de modo que ele para o usuário para ser um único documento.  O resultado é um “documento composto” feitas de item OLE e um documento recipiente.  
  
 Um item OLE pode ser inserido ou associado.  Se for inserida, os dados são armazenados como parte do documento composto.  Se são associados, os dados são armazenados como parte de um arquivo separado criado pelo aplicativo para servidores, e somente um link para o arquivo é armazenado no documento composto.  Todos os itens VELHOS contêm informações que especifica o aplicativo para servidores que deve ser chamado para editá\-los.  
  
 `COleClientItem` define várias funções substituíveis que são chamadas em resposta às solicitações de aplicativo para servidores; esses overridables geralmente agem como notificações.  Isso permite o aplicativo para servidores informar o contêiner de alterações que o usuário faz quando editando o item OLE, ou recuperar as informações necessárias durante a edição.  
  
 `COleClientItem` pode ser usado com a classe de [COleDocument](../../mfc/reference/coledocument-class.md), de [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md), ou de [COleServerDoc](../Topic/COleServerDoc%20Class.md) .  Para usar `COleClientItem`, derive uma classe de ele e implementar a função de membro de [OnChange](../Topic/COleClientItem::OnChange.md) , que define como o contêiner responde às alterações feitas ao item.  Para oferecer suporte a ativação in\-loco, substituir a função de membro de [OnGetItemPosition](../Topic/COleClientItem::OnGetItemPosition.md) .  Essa função fornece informações sobre a posição exibida de item OLE.  
  
 Para obter mais informações sobre como usar a interface continente, consulte os artigos [Recipientes: implementando um contêiner](../../mfc/containers-implementing-a-container.md) e [ativação](../../mfc/activation-cpp.md).  
  
> [!NOTE]
>  Refere\-se [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] inseriu e vinculou itens como “objetos e” refere\-se tipos de itens como “classes.” Usa essa referência o termo “item” distinguir a entidade OLE do objeto correspondente C\+\+ e o termo “tipo” para distinguir a categoria OLE da classe C\+\+.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 `COleClientItem`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [Exemplo MFCBIND MFC](../../top/visual-cpp-samples.md)   
 [Exemplo OCLIENT MFC](../../top/visual-cpp-samples.md)   
 [Classe de CDocItem](../../mfc/reference/cdocitem-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleServerItem](../../mfc/reference/coleserveritem-class.md)