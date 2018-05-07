---
title: Cadeias de caracteres de modelo, Assistente de aplicativo MFC documento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.appwiz.mfc.exe.doctemp
dev_langs:
- C++
helpviewer_keywords:
- MFC Application Wizard, document template strings
ms.assetid: 8109f662-3182-4682-977a-2503321c678a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7d6039459eed097af5e927c4bd2f30d3e7c3c4bc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="document-template-strings-mfc-application-wizard"></a>Cadeias de caracteres de modelo do documento, Assistente de Aplicativo MFC
Nesta página do Assistente de aplicativo MFC, fornecer ou refinar as seguintes opções para ajudá-lo a localização e o gerenciamento de documentos. Cadeias de caracteres de modelo de documento estão disponíveis para aplicativos que incluem **suporte para a arquitetura de documento/exibição** no [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md). Eles não estão disponíveis para caixas de diálogo. Como a maioria das cadeias de caracteres de modelo de documento são visíveis e usado por usuários do aplicativo, eles são localizados no **idioma de recurso** indicado no **tipo de aplicativo** página do assistente.  
  
 **Cadeias de caracteres não localizadas**  
 Aplica-se a aplicativos que criam documentos do usuário. Os usuários podem abrir, imprimir e salvar os documentos mais facilmente se você fornecer uma extensão de arquivo e a ID do tipo de arquivo. Esses itens não são localizados, porque eles são usados pelo sistema e não pelo usuário.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Extensão de arquivo**|Define a extensão de arquivo associada aos documentos que o usuário salva usando o aplicativo. Por exemplo, se seu projeto for chamado Widget, você pode nomear o .wgt de extensão de arquivo. (Quando você digitar a extensão de arquivo, não inclua o período.)<br /><br /> Se você fornecer uma extensão de arquivo, o Pesquisador de objetos pode imprimir documentos do aplicativo sem iniciar seu aplicativo quando o usuário solta o ícone do documento em um ícone de impressora.<br /><br /> Se você não especificar uma extensão, um usuário deve especificar uma extensão de arquivo ao salvar arquivos. O assistente não fornece uma extensão de arquivo padrão.|  
|**ID do tipo de arquivo**|Define o rótulo para o tipo de documento no registro do sistema.|  
  
 **Cadeias de caracteres localizadas**  
 Produz cadeias de caracteres associadas ao aplicativo e o documento que são lidos e usado por usuários do aplicativo, portanto, as cadeias de caracteres são localizadas.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Linguagem**|Indica o idioma no qual as cadeias de caracteres são exibidas para todas as caixas em **localizado cadeias de caracteres**. Para alterar o valor nessa caixa, selecione o idioma apropriado em **idioma de recurso** no [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página do Assistente de aplicativo MFC.|  
|**Legenda do quadro principal**|Define o texto que aparece na parte superior do quadro principal do aplicativo. Por padrão, o nome do projeto.|  
|**Nome do tipo de documento**|Identifica o tipo de documento no qual um documento do aplicativo pode ser agrupado. Por padrão, o nome do projeto. Alterar o padrão não altera qualquer outra opção na caixa de diálogo.|  
|**Nome do filtro**|Define o nome que os usuários podem indicar para localizar arquivos de seu tipo de arquivo. Essa opção está disponível na **arquivos do tipo** e **Salvar como tipo** opções padrão do Windows **abrir** e **Salvar como** caixas de diálogo. Por padrão, o nome do projeto mais arquivos, seguido pela extensão fornecido na **extensão de arquivo**. Por exemplo, se seu projeto for chamado Widget, e a extensão de arquivo é .wgt, o **nome do filtro** é Widget arquivos (*.wgt) por padrão.|  
|**Nome curto do novo arquivo**|Define o nome que aparece no padrão do Windows `New` caixa de diálogo, se houver mais de um novo modelo de documento. Se seu aplicativo for um [servidor de automação](../../mfc/automation-servers.md), esse nome é usado como o nome curto de seu objeto de automação. Por padrão, o nome do projeto.|  
|**Nome longo do tipo de arquivo**|Define o nome do tipo de arquivo no registro do sistema. Se seu aplicativo for um servidor de automação, esse nome é usado como o nome longo de seu objeto de automação. Por padrão, o nome do projeto mais. Documento.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)

