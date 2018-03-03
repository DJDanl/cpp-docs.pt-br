---
title: Suporte a documento, Assistente de aplicativo MFC composto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfc.exe.compdoc
dev_langs:
- C++
ms.assetid: 42e1af83-12c4-438d-92eb-13835afdb148
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9390f3849cd7511054f1248205c5d2c408cb7e71
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compound-document-support-mfc-application-wizard"></a>Suporte a documento composto, Assistente de Aplicativo MFC
Nesta página do Assistente de aplicativo MFC, indica o nível de seu aplicativo fornece suporte a documentos compostos e ativo. O aplicativo deve oferecer suporte a arquitetura de documento/exibição para dar suporte a documentos compostos e modelos de documento.  
  
 Por padrão, o aplicativo não contém nenhum suporte a documentos compostos. Se você aceitar esse padrão, seu aplicativo não ofereça suporte documentos ativos ou arquivos compostos.  
  
 **Suporte a documento composto**  
 Determina se o seu aplicativo fornece suporte de contêiner, o suporte do servidor ou ambos. Para obter mais informações sobre essa área, consulte:  
  
-   [Contêineres: implementando um contêiner](../../mfc/containers-implementing-a-container.md)  
  
-   [Servidores: implementando um servidor](../../mfc/servers-implementing-a-server.md)  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Nenhum**|Indica que não há suporte para vinculação e incorporação (OLE). Por padrão, o Assistente de aplicativo cria um aplicativo sem suporte do ActiveX.|  
|**Contêiner**|Contém os objetos vinculados e incorporados.|  
|**Servidor Mini**|Indica que o aplicativo pode criar e gerenciar objetos de documento composto. Observe que não é possível executar a miniservidores autônomo e oferecem suporte apenas a itens incorporados.|  
|**Servidor completo**|Indica que o aplicativo pode criar e gerenciar objetos de documento composto. Servidores completos são capazes de executar autônomo e suporte a ambos vinculam e inseridos itens.|  
|**Servidor de contêiner/completo**|Indica que o aplicativo pode ser um contêiner e um servidor. Um contêiner é um aplicativo que pode incorporar itens incorporados ou vinculados em seus próprios documentos. Um servidor é um aplicativo que pode criar itens de automação para uso por aplicativos de contêiner.|  
  
 **Opções adicionais**  
 Indica se o seu aplicativo dá suporte a documentos ativos. Consulte [documentos ativos](../../mfc/active-documents.md) para obter mais informações sobre esse recurso.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Servidor do documento ativo**|Indica que o aplicativo pode criar e gerenciar documentos ativos. Se você selecionar essa opção, você deve especificar uma extensão de arquivo para o servidor de documento ativo no **extensão de arquivo** caixa o [cadeias de caracteres de modelo de documento](../../mfc/reference/document-template-strings-mfc-application-wizard.md) página do assistente. Consulte [servidores ativos do documento](../../mfc/active-document-servers.md) para obter mais informações.|  
|**Contêiner de documentos ativos**|Indica que o aplicativo pode conter documentos ativos dentro do quadro. Documentos ativos podem incluir, por exemplo, documentos do Internet Explorer ou documentos do Office, como arquivos do Microsoft Word ou planilhas do Excel. Consulte [contenção de documento ativo](../../mfc/active-document-containment.md) para obter mais informações.|  
|**Suporte para arquivos compostos**|Não serializar documentos do aplicativo de contêiner usando o formato de arquivo composto. Essa opção força o carregamento de um arquivo inteiro que contém objetos na memória. Salva incremental para objetos individuais não está disponível. Se um objeto é alterado e, posteriormente, salvos, todos os objetos no arquivo são salvas.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)

