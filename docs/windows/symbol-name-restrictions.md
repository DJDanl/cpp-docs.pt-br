---
title: Restrições de nome de símbolo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.symbol.restrictions.name
dev_langs:
- C++
helpviewer_keywords:
- symbol names
- symbols, names
- restrictions, symbol names
ms.assetid: 4ae7f695-ca86-4f4b-989a-fe6f89650ff7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 59ee6ce257609c4761e43630a66de9cb9b996269
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892329"
---
# <a name="symbol-name-restrictions"></a>Restrições de nome do símbolo
As restrições em nomes de símbolos são da seguinte maneira:  
  
-   Todos os [símbolos](../windows/symbols-resource-identifiers.md) devem ser exclusivos dentro do escopo do aplicativo. Isso impede que as definições de símbolo conflitantes nos arquivos de cabeçalho.  
  
-   Caracteres válidos para um nome de símbolo incluem A-Z, a-z, 0-9 e sublinhados (_).  
  
-   Nomes de símbolo não podem começar com um número e são limitados a 247 caracteres.  
  
-   Nomes de símbolo não podem conter espaços.  
  
-   Nomes de símbolos não diferenciam maiusculas de minúsculas, mas no caso da primeira definição de símbolo é preservado. O arquivo de cabeçalho que define os símbolos é usado pelo compilador de recurso e editor e programas C++ para fazer referência a recursos definidos em um arquivo de recurso. Para os dois nomes de símbolos que diferem somente no caso, o programa do C++ verá dois símbolos separados enquanto o editor/compilador de recurso verá ambos os nomes de como fazer referência a um único símbolo.  
  
    > [!NOTE]
    >  Se você não seguir o esquema de nome de símbolo padrão (ID*_[keyword]) descritas abaixo, e seu nome de símbolo é o mesmo como uma palavra-chave conhecida para o compilador de script de recurso, tentar criar o arquivo de script de recurso resultará em erro aparentemente aleatório geração, que é difícil diagnosticar. Para evitar isso, seguir o esquema de nomenclatura padrão.  
  
 Nomes de símbolos têm prefixos descritivos que indicam o tipo de recurso ou objeto que eles representam. Esses prefixos descritivos começam com a ID da combinação de texto. O Microsoft Foundation Class Library (MFC) usa as convenções de nomenclatura de símbolo mostradas na tabela a seguir.  
  
|Categoria|Prefixo|Use|  
|--------------|------------|---------|  
|Recursos|IDR IDD _ IDC _ IDI_ IDB_|Acelerador de menu (e recursos associados ou personalizados) a caixa de diálogo Bitmap de ícone de Cursor|  
|Itens de menu|ID _|Item de menu|  
|Comandos|ID _|Comando|  
|Controles e janelas filho|IDC _|Controle|  
|Cadeias de caracteres|IDS _|Cadeia de caracteres na tabela de cadeia de caracteres|  
|MFC|AFX_|Reservado para símbolos predefinidos do MFC|  
  

  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Alterando um símbolo ou um nome de símbolo (ID)](../windows/changing-a-symbol-or-symbol-name-id.md)   
 [Restrições de valor do símbolo](../windows/symbol-value-restrictions.md)   
 [IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)