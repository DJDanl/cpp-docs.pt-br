---
title: Suporte a documento, Assistente de aplicativo MFC composto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.appwiz.mfc.exe.compdoc
dev_langs:
- C++
ms.assetid: 42e1af83-12c4-438d-92eb-13835afdb148
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2d15522581b67a78cbbe3925d9166cd8cd9e00b1
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720207"
---
# <a name="compound-document-support-mfc-application-wizard"></a>Suporte a documento composto, Assistente de Aplicativo MFC
Nesta página do Assistente de aplicativo MFC, indica para qual nível de seu aplicativo fornece suporte a documentos compostos e Active Directory. Seu aplicativo deve oferecer suporte a arquitetura de documento/exibição para dar suporte a documentos compostos e os modelos de documento.  
  
 Por padrão, o aplicativo não contém nenhum suporte a documentos compostos. Se você aceitar esse padrão, seu aplicativo não pode dar suporte a documentos ativos ou arquivos compostos.  
  
- **Suporte a documento composto**

   Determina se o seu aplicativo oferece suporte a contêiner, o suporte do servidor ou ambos. Para obter mais informações sobre essa área, consulte:  
  
   - [Contêineres: implementando um contêiner](../../mfc/containers-implementing-a-container.md)  
  
   - [Servidores: implementando um servidor](../../mfc/servers-implementing-a-server.md)  
  
   |Opção|Descrição|  
   |------------|-----------------|  
   |**Nenhum**|Indica que não há suporte para vinculação e incorporação (OLE). Por padrão, o Assistente de aplicativo cria um aplicativo sem suporte do ActiveX.|  
   |**Contêiner**|Contém os objetos vinculados e incorporados.|  
   |**Minisservidor**|Indica que o aplicativo pode criar e gerenciar objetos de documento composto. Observe que não é possível executar a miniservidores autônomo e só há suporte para itens inseridos.|  
   |**Servidor completo**|Indica que o aplicativo pode criar e gerenciar objetos de documento composto. Servidores completos são capazes de executar autônomo e suporte a ambos vinculados e inseridos itens.|  
   |**Contêiner/servidor completo**|Indica que o aplicativo pode ser um contêiner e um servidor. Um contêiner é um aplicativo que pode incorporar itens inseridos ou vinculados em seus próprios documentos. Um servidor é um aplicativo que pode criar itens de automação para uso por aplicativos de contêiner.|  
  
- **Opções adicionais**

   Indica se o seu aplicativo dá suporte a documentos ativos. Ver [documentos ativos](../../mfc/active-documents.md) para obter mais informações sobre esse recurso.  
  
   |Opção|Descrição|  
   |------------|-----------------|  
   |**Servidor de documento ativo**|Indica que o aplicativo pode criar e gerenciar documentos ativos. Se você selecionar essa opção, você deve especificar uma extensão de arquivo para seu servidor de documento ativo na **extensão de arquivo** caixa de [cadeias de caracteres de modelo de documento](../../mfc/reference/document-template-strings-mfc-application-wizard.md) página do assistente. Ver [servidores de documento ativos](../../mfc/active-document-servers.md) para obter mais informações.|  
   |**Contêiner de documento ativo**|Indica que o aplicativo pode conter documentos ativos dentro do quadro. Documentos ativos podem incluir, por exemplo, documentos do Internet Explorer ou documentos do Office, como arquivos do Microsoft Word ou planilhas do Excel. Ver [contenção de documento ativo](../../mfc/active-document-containment.md) para obter mais informações.|  
   |**Suporte para arquivos compostos**|Não serializar os documentos do aplicativo de contêiner usando o formato de arquivo composto. Essa opção força o carregamento de um arquivo inteiro que contém os objetos na memória. Salva incremental para objetos individuais não está disponível. Se um objeto é alterado e, posteriormente, salvos, todos os objetos no arquivo são salvas.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)

