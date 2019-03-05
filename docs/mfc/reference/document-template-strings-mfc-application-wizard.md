---
title: Cadeias de caracteres de modelo do documento, Assistente de Aplicativo MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.exe.doctemp
helpviewer_keywords:
- MFC Application Wizard, document template strings
ms.assetid: 8109f662-3182-4682-977a-2503321c678a
ms.openlocfilehash: 563cdf51c8104035fe29cb2e11d6c2bc8155d97b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57297457"
---
# <a name="document-template-strings-mfc-application-wizard"></a>Cadeias de caracteres de modelo do documento, Assistente de Aplicativo MFC

Nesta página do Assistente de aplicativo MFC, fornecer ou refinar as seguintes opções para ajudar com a localização e o gerenciamento de documentos. Cadeias de caracteres de modelo de documento estão disponíveis para aplicativos que incluem **suporte de arquitetura de documento/exibição** na [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md). Eles não estão disponíveis para caixas de diálogo. Como a maioria das cadeias de caracteres de modelo de documento são visíveis e usado por usuários do aplicativo, eles são localizados na **idioma de recurso** indicado na **tipo de aplicativo** página do assistente.

- **Cadeias de caracteres não localizadas**

   Aplica-se a aplicativos que criam documentos do usuário. Os usuários podem abrir, imprimir e salvar documentos muito mais fácil se você fornecer uma extensão de arquivo e a ID do tipo de arquivo. Esses itens não são localizados, porque eles são usados pelo sistema em vez do usuário.

   |Opção|Descrição|
   |------------|-----------------|
   |**Extensão de arquivo**|Define a extensão de arquivo associada com os documentos que o usuário salva usando o aplicativo. Por exemplo, se seu projeto é chamado Widget, você pode nomear o .wgt de extensão de arquivo. (Quando você insere a extensão de arquivo, não inclua o período.)<br /><br /> Se você fornecer uma extensão de arquivo, o Gerenciador pode imprimir documentos do seu aplicativo sem iniciar seu aplicativo quando o usuário solta o ícone do documento em um ícone de impressora.<br /><br /> Se você não especificar uma extensão, um usuário deve especificar uma extensão de arquivo ao salvar arquivos. O assistente não fornece uma extensão de arquivo padrão.|
   |**ID do tipo de arquivo**|Define o rótulo para o tipo de documento no registro do sistema.|

- **Cadeias de caracteres localizadas**

   Produz a cadeias de caracteres associadas de aplicativo e do documento que são lidos e usados por usuários do aplicativo, portanto, as cadeias de caracteres são localizadas.

   |Opção|Descrição|
   |------------|-----------------|
   |**Linguagem**|Indica o idioma no qual as cadeias de caracteres são exibidas para todas as caixas em **strings localizadas**. Para alterar o valor nessa caixa, selecione o idioma apropriado sob **idioma de recurso** na [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página do Assistente de aplicativo MFC.|
   |**Legenda do quadro principal**|Define o texto que aparece na parte superior do quadro principal do aplicativo. Por padrão, o nome do projeto.|
   |**Nome do tipo de documento**|Identifica o tipo de documento sob a qual um documento do aplicativo pode ser agrupado. Por padrão, o nome do projeto. Alterando o padrão não altera quaisquer outras opções na caixa de diálogo.|
   |**Nome do filtro**|Define o nome que os usuários podem indicar para localizar arquivos de seu tipo de arquivo. Essa opção está disponível na **arquivos de tipo** e **Salvar como tipo** opções no Windows padrão **abrir** e **Salvar como** caixas de diálogo. Por padrão, o nome do projeto além de arquivos, seguido pela extensão fornecida no **extensão de arquivo**. Por exemplo, se seu projeto for chamado Widget, e a extensão de arquivo é .wgt, o **nome do filtro** for o Widget arquivos (*.wgt) por padrão.|
   |**Nome curto do arquivo novo**|Define o nome que aparece no Windows padrão **New** caixa de diálogo, se houver mais de um novo modelo de documento. Se seu aplicativo for um [servidor de automação](../../mfc/automation-servers.md), esse nome é usado como o nome curto do seu objeto de automação. Por padrão, o nome do projeto.|
   |**Nome longo do tipo de arquivo**|Define o nome do tipo de arquivo no registro do sistema. Se seu aplicativo for um servidor de automação, esse nome é usado como o nome longo de seu objeto de automação. Por padrão, o adição do nome do projeto. Documento.|

## <a name="see-also"></a>Consulte também

[Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)
