---
title: "TN020: ID de nomenclatura e numeração convenções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.id
dev_langs:
- C++
helpviewer_keywords:
- TN020
- resource identifiers, naming and numbering
- resource identifiers
ms.assetid: aecbd2cf-68b3-47f6-ae21-b1f507917245
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a666c2183276b95a9405400de8acc0117c7134e1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn020-id-naming-and-numbering-conventions"></a>TN020: convenções de nomenclatura de ID e numeração
Esta anotação descreve a nomenclatura de ID e numeração convenções MFC 2.0 usa para recursos, comandos, cadeias de caracteres, controles e janelas filho.  
  
 A ID do MFC de nomenclatura e numeração convenções destinam-se para atender aos seguintes requisitos:  
  
-   Fornece um padrão de nomenclatura de ID consistente usado pela biblioteca do MFC e aplicativos do MFC que são suportados pelo editor de recursos do Visual C++. Isso torna mais fácil para o programador interpretar o tipo e a origem de um recurso de sua ID.  
  
-   Enfatize a relação de 1 a 1 forte entre certos tipos de IDs.  
  
-   Em conformidade com padrões já amplamente usados para nomear IDs no Windows.  
  
-   O espaço de numeração de ID da partição. Números de identificação podem ser atribuídos pelo programador, MFC, Windows e recursos do Visual C++ editados. Particionamento apropriadas ajudará a evitar a duplicação dos números de ID.  
  
## <a name="the-id-prefix-naming-convention"></a>A convenção de nomenclatura de prefixo de ID  
 Vários tipos de IDs podem ocorrer em um aplicativo. A convenção de nomenclatura de ID de MFC define prefixos diferentes para diferentes tipos de recursos.  
  
 MFC usa o prefixo "IDR" para indicar uma ID de recurso que se aplica a vários tipos de recurso. Por exemplo, para uma janela do quadro especificado, o MFC usa o mesmo prefixo "IDR" para indicar um recurso de menu, acelerador, cadeia de caracteres e ícone. A tabela a seguir mostra os vários prefixos e seu uso:  
  
|Prefixo|Use|  
|------------|---------|  
|IDR|Para vários tipos de recurso (usados principalmente para menus, aceleradores e faixas de opções).|  
|IDD _|Para recursos de modelo de caixa de diálogo (por exemplo, IDD_DIALOG1).|  
|IDC _|Para recursos do cursor.|  
|IDI_|Para recursos de ícone.|  
|IDB_|Para recursos do bitmap.|  
|IDS _|Para recursos de cadeia de caracteres.|  
  
 Dentro de um recurso de caixa de diálogo, MFC segue as seguintes convenções:  
  
|Prefixo ou rótulo|Use|  
|---------------------|---------|  
|IDOK, IDCANCEL|Para o botão de ação padrão IDs.|  
|IDC _|Para outros controles de caixa de diálogo.|  
  
 O prefixo "IDC _" também é usado para cursores. Esse conflito de nomeação não é geralmente um problema porque um aplicativo típico terá alguns cursores e muitos controles de caixa de diálogo.  
  
 Dentro de um recurso de menu, MFC segue as seguintes convenções:  
  
|Prefixo|Use|  
|------------|---------|  
|IDM_|Itens de menu que não usam a arquitetura de comando do MFC.|  
|ID _|Comandos de menu que usam a arquitetura de comando do MFC.|  
  
 Comandos que siga a arquitetura de comando MFC devem ter uma `ON_COMMAND` manipulador de comando e pode ter um `ON_UPDATE_COMMAND_UI` manipulador. Se esses manipuladores de comando siga a arquitetura de comando do MFC, eles funcionarão corretamente se eles estão associados a um comando de menu, um botão de barra de ferramentas ou um botão de barra da caixa de diálogo. O mesmo prefixo de "ID _" também é usado para uma sequência de prompt de menu é exibida na barra de mensagens do programa. A maioria dos itens de menu em seu aplicativo deve seguir as convenções de comando do MFC. Todas as do padrão de IDs de comando (por exemplo, `ID_FILE_NEW`) seguem a convenção.  
  
 MFC também usa "IDP_" como uma forma especializada de cadeias de caracteres (em vez de "IDs _"). Cadeias de caracteres com o prefixo "IDP_" são avisos, isto é, cadeias de caracteres usadas nas caixas de mensagem. Cadeias de caracteres "IDP_" podem conter "%1" e "%2" como espaços reservados de determinado pelo programa de cadeias de caracteres. Cadeias de caracteres "IDP_" geralmente têm tópicos da Ajuda associados a eles, e cadeias de caracteres "IDs _" não. Cadeias de caracteres "IDP_" sempre estão localizadas e cadeias de caracteres "IDs _" não podem ser localizadas.  
  
 A biblioteca do MFC também usa o prefixo "IDW_" como uma forma especializada de controle IDs (em vez de "IDC _"). Essas IDs são atribuídos a janelas filho como divisores e exibições, as classes do framework. IDs de implementação MFC são prefixadas com "AFX_".  
  
## <a name="the-id-numbering-convention"></a>A convenção de numeração de ID  
 A tabela a seguir lista os intervalos válidos para as IDs dos tipos específicos. Alguns dos limites são os limites de implementação técnica e outros são convenções são projetadas para evitar que suas IDs de colisão com IDs predefinidas do Windows ou do MFC implementações padrão.  
  
 É altamente recomendável que você defina todas as IDs de dentro dos intervalos recomendados. O limite inferior desses intervalos é 1 como 0 não é usado. É recomendável que você use a convenção comum e usa 100 ou 101 como a ID do primeiro.  
  
|Prefixo|Tipo de recurso|Intervalo válido|  
|------------|-------------------|-----------------|  
|IDR|vários|1 a 0x6FFF|  
|IDD _|modelos de caixa de diálogo|1 a 0x6FFF|  
|IDC _, IDI_, IDB_|cursores, ícones, bitmaps|1 a 0x6FFF|  
|IDS _, IDP_|cadeias de caracteres gerais|1 a 0x7FFF|  
|ID _|comandos|0x8000 por meio de 0xDFFF|  
|IDC _|controles|8 a 0xDFFF|  
  
 Razões para esses limites de intervalo.  
  
-   Por convenção, o valor da ID de 0 não é usado.  
  
-   Limitações de implementação do Windows restringem IDs para ser menor ou igual a 0x7FFF verdadeira do recurso.  
  
-   Estrutura interna do MFC reserva esses intervalos:  
  
    -   0x7000 por meio de 0x7FFF (consulte afxres.h)  
  
    -   0xE000 por meio de 0xEFFF (consulte afxres.h)  
  
    -   16000 por meio de 18000 (consulte afxribbonres.h)  
  
     Esses intervalos podem ser alteradas no futuro implementações MFC.  
  
-   Vários comandos de sistema do Windows usam o intervalo de 0xF000 a 0xFFFF.  
  
-   IDs de controle de 1 a 7 são reservados para controles padrão como IDOK e IDCANCEL.  
  
-   O intervalo de 0x8000 a 0xFFFF para cadeias de caracteres é reservado para instruções para os comandos do menu.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

