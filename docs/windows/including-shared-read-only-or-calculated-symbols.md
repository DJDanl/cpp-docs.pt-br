---
title: Incluindo compartilhados (somente leitura) ou calculados símbolos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.symbol.shared.calculated
dev_langs:
- C++
helpviewer_keywords:
- symbols, read-only
- symbols, shared
- symbols, calculated
- read-only symbols
- symbol directives
- calculated symbols
- shared symbols
ms.assetid: 32b77faf-a066-4371-a072-9a5b84c0766d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c56e8af65d27bda8ef04655f40bdd2e335067d3c
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33879221"
---
# <a name="including-shared-read-only-or-calculated-symbols"></a>Incluindo símbolos compartilhados (somente leitura) ou calculados
Na primeira vez que o ambiente de desenvolvimento lê um arquivo de recurso criado por outro aplicativo, ele marca todos os arquivos de cabeçalho incluído como somente leitura. Em seguida, você pode usar o [caixa de diálogo recurso inclui](../windows/resource-includes-dialog-box.md) para adicionar arquivos de cabeçalho de símbolo adicionais de somente leitura.  
  
 É um motivo que você talvez queira usar definições de símbolo de somente leitura para os arquivos de símbolo que você planeja compartilhar entre vários projetos.  
  
 Você também pode usar arquivos de símbolo incluído quando você tem os recursos existentes com as definições de símbolo que usam expressões em vez de inteiros simples para definir o valor do símbolo. Por exemplo:  
  
```  
#define   IDC_CONTROL1 2100  
#define   IDC_CONTROL2 (IDC_CONTROL1+1)  
```  
  
 O ambiente corretamente interpretará esses símbolos calculados, contanto que:  
  
-   Os símbolos calculados são colocados em um arquivo de símbolos de somente leitura.  
  
-   O arquivo de recurso contém recursos para que esses símbolos calculados já estão atribuídos.  
  
-   Uma expressão numérica é esperada.  
  
> [!NOTE]
>  Se uma cadeia de caracteres ou uma expressão numérica é esperada, a expressão não é avaliada.  
  
### <a name="to-include-shared-read-only-symbols-in-your-resource-file"></a>Para incluir os símbolos compartilhados (somente leitura) em seu arquivo de recurso  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), clique em seu arquivo. RC e escolha [inclui recursos](../windows/resource-includes-dialog-box.md) no menu de atalho.  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **diretivas de símbolo somente leitura** caixa, use o **#include** diretiva de compilador para especificar o arquivo onde você deseja que os símbolos somente leitura sejam mantidos.  
  
     Não chame o arquivo Resource.h, já que esse é o nome de arquivo normalmente é usado pelo arquivo de cabeçalho de símbolo principal.  
  
    > [!NOTE]
    >  **Importante** o que você digita na caixa de diretivas de símbolo somente leitura está incluído no arquivo de recurso exatamente como você a digita. Certifique-se de que você digitou não contém erros de ortografia ou de sintaxe.  
  
     Use o **diretivas de símbolo somente leitura** caixa para incluir arquivos com apenas definições de símbolo. Não inclua as definições de recurso. Caso contrário, as definições de recurso duplicado serão criadas quando o arquivo é salvo.  
  
3.  Coloque os símbolos no arquivo especificado.  
  
     Os símbolos nos arquivos incluídos dessa maneira são avaliados sempre que você abrir o arquivo de recurso, mas elas não são substituídas no disco quando você salvar o arquivo.  
  
4.  Clique em **OK**.  
  

  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Restrições de nome de símbolo](../windows/symbol-name-restrictions.md)   
 [Restrições de valor do símbolo](../windows/symbol-value-restrictions.md)   
 [IDs de símbolo predefinido](../windows/predefined-symbol-ids.md)   
 [Símbolos: identificadores de recursos](../windows/symbols-resource-identifiers.md)