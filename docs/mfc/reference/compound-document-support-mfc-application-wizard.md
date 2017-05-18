---
title: Suporte a documento, Assistente de aplicativo MFC composto | Documentos do Microsoft
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
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e322824bd2887b50d72221cee67e2ba5cc46f2ea
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compound-document-support-mfc-application-wizard"></a>Suporte a documento composto, Assistente de Aplicativo MFC
Nesta página do Assistente de aplicativo MFC, indica até que ponto seu aplicativo oferece suporte a documentos compostos e ativo. Seu aplicativo deve oferecer suporte à arquitetura de exibição de documentos para dar suporte a documentos compostos e modelos de documento.  
  
 Por padrão, o aplicativo não contém nenhum suporte a documentos compostos. Se você aceitar esse padrão, seu aplicativo não oferecer suporte documentos ativos ou arquivos compostos.  
  
 **Suporte a documento composto**  
 Determina se o seu aplicativo fornece suporte de contêiner, suporte ao servidor ou ambos. Para obter mais informações sobre essa área, consulte:  
  
-   [Contêineres: Implementando um contêiner](../../mfc/containers-implementing-a-container.md)  
  
-   [Servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md)  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Nenhum**|Indica que não há suporte para vinculação e incorporação de objetos (OLE). Por padrão, o Assistente para aplicativo cria um aplicativo sem suporte do ActiveX.|  
|**Contêiner**|Contém objetos vinculados e incorporados.|  
|**Minisservidor**|Indica que o aplicativo pode criar e gerenciar objetos de documento composto. Observe que não é possível executar a miniservidores autônomo e dão suporte apenas a itens inseridos.|  
|**Servidor completo**|Indica que o aplicativo pode criar e gerenciar objetos de documento composto. Servidores completos são capazes de executar autônomo e suporte a ambos vinculados e inseridos itens.|  
|**Servidor completo/contêiner**|Indica que o aplicativo pode ser um contêiner e um servidor. Um contêiner é um aplicativo que pode incorporar itens inseridos ou vinculados em seus próprios documentos. Um servidor é um aplicativo que pode criar itens de automação para uso por aplicativos de contêiner.|  
  
 **Opções adicionais**  
 Indica se o aplicativo suportar documentos ativos. Consulte [documentos ativos](../../mfc/active-documents.md) para obter mais informações sobre esse recurso.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Servidor do documento ativo**|Indica que o aplicativo pode criar e gerenciar documentos ativos. Se você selecionar essa opção, você deve especificar uma extensão de arquivo para o servidor do documento ativo no **extensão de arquivo** caixa de [cadeias de caracteres de modelo de documento](../../mfc/reference/document-template-strings-mfc-application-wizard.md) página do assistente. Consulte [servidores ativos do documento](../../mfc/active-document-servers.md) para obter mais informações.|  
|**Contêiner de documentos ativos**|Indica que o aplicativo pode conter documentos ativos dentro do quadro. Documentos ativos podem incluir, por exemplo, documentos do Internet Explorer ou documentos do Office, como arquivos do Microsoft Word ou planilhas do Excel. Consulte [contenção de documento ativo](../../mfc/active-document-containment.md) para obter mais informações.|  
|**Suporte para arquivos compostos**|Não serializar documentos do aplicativo de contêiner usando o formato de arquivo composto. Essa opção força o carregamento de um arquivo inteiro contendo objetos na memória. Salva incremental para objetos individuais não está disponíveis. Se um objeto é alterado e, posteriormente, salvos, todos os objetos no arquivo são salvas.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)


