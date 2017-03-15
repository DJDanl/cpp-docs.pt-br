---
title: Cadeias de caracteres de modelo, Assistente de aplicativo MFC documento | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfc.exe.doctemp
dev_langs:
- C++
helpviewer_keywords:
- MFC Application Wizard, document template strings
ms.assetid: 8109f662-3182-4682-977a-2503321c678a
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 2feacba30f43ddcdde8250c21aca3d6b835307d5
ms.lasthandoff: 02/25/2017

---
# <a name="document-template-strings-mfc-application-wizard"></a>Cadeias de caracteres de modelo do documento, Assistente de Aplicativo MFC
Nesta página do Assistente de aplicativo MFC, fornecer ou refinar as opções a seguir para ajudar na localização e gerenciamento de documentos. Cadeias de caracteres de modelo de documento estão disponíveis para aplicativos que incluem **suporte para a arquitetura de documento/exibição** no [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md). Eles não estão disponíveis para caixas de diálogo. Como a maioria das cadeias de caracteres de modelo de documento são visíveis e usado por usuários do aplicativo, eles são localizados na **idioma de recurso** indicado no **tipo de aplicativo** página do assistente.  
  
 **Cadeias de caracteres não localizadas**  
 Aplica-se a aplicativos que criam documentos do usuário. Os usuários podem abrir, imprimir e salvar documentos muito mais fácil se você fornecer uma extensão de arquivo e a ID do tipo de arquivo. Esses itens não são localizados, porque eles são usados pelo sistema e não pelo usuário.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Extensão de arquivo**|Define a extensão de arquivo associada aos documentos que o usuário salva usando o aplicativo. Por exemplo, se seu projeto for chamado Widget, você poderia chamar o .wgt de extensão de arquivo. (Quando você digitar a extensão de arquivo, não inclui o período).<br /><br /> Se você fornecer uma extensão de arquivo, o Gerenciador pode imprimir documentos do aplicativo sem iniciar seu aplicativo quando o usuário cancela o ícone do documento em um ícone de impressora.<br /><br /> Se você não especificar uma extensão, um usuário deve especificar uma extensão de arquivo ao salvar arquivos. O assistente não fornece uma extensão de arquivo padrão.|  
|**ID do tipo de arquivo**|Define o rótulo para o tipo de documento no registro do sistema.|  
  
 **Cadeias de caracteres localizadas**  
 Produz cadeias de caracteres associadas ao aplicativo e documento que são lidos e usados pelos usuários do aplicativo, para que as cadeias de caracteres são localizadas.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Linguagem**|Indica o idioma no qual as cadeias de caracteres são exibidas para todas as caixas em **strings localizadas**. Para alterar o valor nessa caixa, selecione o idioma apropriado em **idioma de recurso** no [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página do Assistente de aplicativo MFC.|  
|**Legenda do quadro principal**|Define o texto que aparece na parte superior do quadro principal do aplicativo. Por padrão, o nome do projeto.|  
|**Nome do tipo de documento**|Identifica o tipo de documento no qual um documento do aplicativo pode ser agrupado. Por padrão, o nome do projeto. Alterar o padrão não altera quaisquer outras opções na caixa de diálogo.|  
|**Nome do filtro**|Define o nome que os usuários podem indicar para localizar os arquivos do seu tipo de arquivo. Essa opção está disponível na **arquivos do tipo** e **Salvar como tipo** opções padrão do Windows **abrir** e **Salvar como** caixas de diálogo. Por padrão, o nome do projeto e arquivos, seguido pela extensão fornecida no **extensão de arquivo**. Por exemplo, se seu projeto for chamado Widget, e a extensão do arquivo é .wgt, o **nome do filtro** é Widget arquivos (*.wgt) por padrão.|  
|**Nome curto do arquivo novo**|Define o nome que aparece no padrão do Windows `New` caixa de diálogo, se houver mais de um novo modelo de documento. Se seu aplicativo é um [servidor de automação](../../mfc/automation-servers.md), esse nome é usado como o nome curto do seu objeto de automação. Por padrão, o nome do projeto.|  
|**Nome completo do tipo de arquivo**|Define o nome do tipo de arquivo no registro do sistema. Se seu aplicativo for um servidor de automação, esse nome é usado como o nome longo de seu objeto de automação. Por padrão, o nome do projeto mais. Documento.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)


