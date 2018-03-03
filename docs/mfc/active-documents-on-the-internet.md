---
title: Documentos ativos na Internet | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- active documents [MFC], creating
- application wizards [MFC], active documents
- active documents [MFC], programming steps
- application wizards [MFC]
- active documents [MFC], using application wizards
ms.assetid: a46bd8a0-e27a-4116-b1bf-dacdb7ae78d1
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0980f048b9be411308b159dea0ceaa71f8eee563
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="active-documents-on-the-internet"></a>Documentos ativos na Internet
Documentos ativos fornecem uma extensão para objetos inseridos tradicionais. Os documentos ativos podem ser várias páginas e são exibidos em toda a área cliente. Eles não negociação de menu tradicionais e podem ser editados no local, bem como em uma janela aberta no aplicativo do servidor. Em vez de exibir como um pequeno retângulo circundado por uma borda tracejada, documentos ativos são quadro completo e ativo sempre no local.  
  
 Documentos ativos podem ser exibidos em um contêiner como o Microsoft Office Binder, que fornece uma maneira de criar um documento composto composto de tipos diferentes de documento como o Excel, Word, e o tipo de documento personalizadas, cada um deles pode ser editado quadro completo. Documentos ativos também podem ser exibidos em um navegador como o Microsoft Internet Explorer, que é um contêiner de documento ativo.  
  
 **Vantagens do documento ativo:**  
  
-   Os documentos podem ser visualizados quadro completo, na janela inteira do cliente.  
  
-   Documentos podem ser abertos em uma janela de aplicativo separado.  
  
     Para o documento a ser aberto, o aplicativo auxiliar deve existir no cliente, ou ser baixado separadamente antes de executar o aplicativo. Um visualizador pode ser gravado para fornecer funcionalidade limitada (Word, PowerPoint e Excel fornece visualizadores para seus documentos). A versão completa do aplicativo pode fornecer suporte completo à edição.  
  
-   Os documentos são sempre ativo no local.  
  
-   Comandos de menu chamados a partir do contêiner podem ser roteados para o documento.  
  
-   Os documentos podem ser visualizados em um navegador da Web. Isso fornece integração perfeita entre seus documentos e outras páginas da Web.  
  
     Um usuário pode navegar em uma página da Web em HTML, em seguida, uma planilha do Excel e, em seguida, para um documento que você tenha escrito usando MFC suporte para documentos ativos. O usuário pode navegar usando a interface familiar da Web, como as opções de navegador entre os menus e modos de exibição de uma página HTML, Excel e o documento do aplicativo.  
  
-   Todos os aplicativos são exibidos em um quadro comuns.  
  
## <a name="requirements-for-active-documents"></a>Requisitos de documentos ativos  
 As interfaces listadas na tabela a seguir incluem interfaces já é necessários para servidores incorporados e várias novas interfaces específicas para documentos ativos. MFC fornece implementações padrão para a maioria dessas interfaces no [COleServerDoc](../mfc/reference/coleserverdoc-class.md) classe.  
  
|Um documento que...|Implementa essas interfaces|  
|-------------------------|---------------------------------|  
|Usa composta arquivos como seu mecanismo de armazenamento.|`IPersistStorage`.|  
|Suporta os recursos básicos de incorporação de documentos ativos, incluindo criar do arquivo.|`IPersistFile`, `IOleObject` e `IDataObject`.|  
|Dá suporte à ativação no local.|`IOleInPlaceObject`e `IOleInPlaceActiveObject` (usando o contêiner `IOleInPlaceSite` e **IOleInPlaceFrame** interfaces).|  
|Oferece suporte as extensões de documento ativo que envolvem essas novas interfaces. Algumas interfaces são opcionais.|`IOleDocument`, `IOleDocumentView`, `IOleCommandTarget` e `IPrint`.|  
  
 MFC fornece suporte para estender o suporte de servidor inserido existente para documentos ativos.  
  
## <a name="add-active-document-support-to-a-new-application"></a>Adicionar suporte para o documento ativo para um novo aplicativo  
 Para criar um novo aplicativo com suporte do documento ativo: no Assistente de aplicativo MFC, no **suporte a documentos compostos** em "suporte a documentos compostos selecione" Escolha **servidor completo** ou  **Contêiner/servidor completo**e em "Selecionadas opções adicionais", marque a caixa de seleção **server documento ativo**.  
  
##  <a name="_core_convert_an_existing_mfc_in.2d.process_server_to_an_activex_document_server"></a>Converter um servidor em processo de MFC existente em um servidor de documento ativo  
 Se seu aplicativo foi criado com uma versão do Visual C++ anteriores à versão 4.2 e já é um servidor em processo, você pode adicionar suporte de documento ativo por meio de alterações para as classes a seguir:  
  
|Tipo de classe|Derivado anteriormente|Alteração de derivar de|  
|----------------|---------------------------|---------------------------|  
|Quadro no local|`COleIPFrameWnd`|**COleDocIPFrameWnd**|  
|Item|`COleServerItem`|`CDocObjectServerItem`|  
  
 Você também alterar como as informações são inseridas no registro e fazer várias outras alterações. Se seu aplicativo tiver atualmente não há suporte para componentes COM, você pode adicionar suporte ao servidor executando o Assistente de aplicativo e integrar o código específico do componente COM o seu aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

