---
title: "Suporte a documento composto, Assistente de Aplicativo MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.mfc.exe.compdoc"
dev_langs: 
  - "C++"
ms.assetid: 42e1af83-12c4-438d-92eb-13835afdb148
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte a documento composto, Assistente de Aplicativo MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Nesta página do assistente de aplicativo MFC, que indica o nível do aplicativo fornece o composto e o suporte do documento ativo.  Seu aplicativo deve oferecer suporte à arquitetura do documento\/exibição para dar suporte a documentos e modelos compostos do documento.  
  
 Por padrão, o aplicativo não contém nenhum suporte composto do documento.  Se você aceitar esta opção, o aplicativo pode não oferecer suporte a documentos ativas ou arquivos compostos.  
  
 **Compound document support**  
 Determina se o aplicativo fornece suporte do contêiner, o suporte do servidor, ou ambos.  Para obter mais informações sobre essa área, consulte:  
  
-   [Contêiner: Implementando um contêiner](../../mfc/containers-implementing-a-container.md)  
  
-   [Servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md)  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Nenhum**|Indica que não há suporte para o objeto que vincula e que insere \(OLE\).  Por padrão, o assistente de aplicativo cria um aplicativo sem suporte ActiveX.|  
|**Contêiner**|Contém vinculados e inseriu objetos.|  
|**Mini servidor**|Indica que o aplicativo possa criar e gerenciar objetos compostos do documento.  Observe que os mini\- servidores não podem executar o suporte apenas e apenas oferecer suporte a itens inseridos.|  
|**Servidor completo**|Indica que o aplicativo possa criar e gerenciar objetos compostos do documento.  Os servidores completo podem executar o suporte apenas e fazê\-lo itens vinculados e inseridos.|  
|**Contêiner\/servidor completo**|Indica que o aplicativo pode ser um contêiner e um servidor.  Um contêiner é um aplicativo que pode inserir itens inseridos ou vinculados em seus próprios documentos.  Um servidor é um aplicativo que pode criar itens de automação para uso por aplicativos de contêiner.|  
  
 **Opções Adicionais**  
 Indica se o seu aplicativo da suporte a documentos ativas.  Consulte [Documentos ativas](../Topic/Active%20Documents.md) para obter mais informações sobre esse recurso.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Servidor ativo do documento**|Indica que o aplicativo pode criar e gerenciar documentos ativas.  Se você selecionar esta opção, você deve especificar uma extensão de arquivo para o servidor ativo do documento na caixa de **Extensão de Arquivo** na página de [Cadeias de caracteres de modelo de documento](../Topic/Document%20Template%20Strings,%20MFC%20Application%20Wizard.md) do assistente.  Consulte [Servidores ativas do documento](../../mfc/active-document-servers.md) para obter mais informações.|  
|**Contêiner do documento ativo**|Indica que o aplicativo pode conter documentos ativas no quadro.  Os documentos ativas podem incluir, por exemplo, documentos do Internet Explorer, ou documentos do Office como arquivos ou planilhas do Excel do Microsoft Word.  Consulte [Retenção do documento ativo](../../mfc/active-document-containment.md) para obter mais informações.|  
|**Suporte para arquivos compostos**|Não serializa os documentos de aplicativo de contêiner usando o formato de composto\-Arquivo.  Essa opção força a carga de um arquivo inteiro que contém objetos na memória.  Incremental salva os objetos individuais não estão disponíveis.  Se um objeto é alterado e salvo, todos os objetos no arquivo serão salvos.|  
  
## Consulte também  
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)