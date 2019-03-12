---
title: Conformidade com ANSI C
ms.date: 11/04/2016
f1_keywords:
- Ansi
helpviewer_keywords:
- underscores, leading
- compatibility [C++], ANSI C
- compliance with ANSI C
- conventions [C++], Microsoft extensions
- underscores
- naming conventions [C++], Microsoft library
- ANSI [C++], C standard
- Microsoft extensions naming conventions
ms.assetid: 6be271bf-eecf-491a-a928-0ee2dd60e3b9
ms.openlocfilehash: 7a4462e84ec01bd236849c6aed024b636b315243
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57742817"
---
# <a name="ansi-c-compliance"></a>Conformidade com ANSI C

A convenção de nomenclatura para todos os identificadores específicos da Microsoft no sistema de tempo de execução (como funções, macros, constantes, variáveis e definições de tipo) está em conformidade com ANSI. Nessa documentação, qualquer função de tempo de execução que segue os padrões ANSI/ISO C é registrada como sendo compatível com ANSI. Os aplicativos em conformidade com ANSI devem usar apenas essas funções compatíveis com ANSI.

Os nomes de funções específicas e de variáveis globais da Microsoft começam com um sublinhado simples. Esses nomes podem ser substituídos apenas localmente, dentro do escopo do seu código. Por exemplo, quando você inclui arquivos de cabeçalho de tempo de execução da Microsoft, ainda pode substituir localmente a função específica da Microsoft chamada `_open` declarando uma variável local de mesmo nome. No entanto, não pode usar esse nome para sua própria função global ou variável global.

Os nomes de macros e constantes de manifesto específicas da Microsoft começam com dois sublinhados ou com um único sublinhado à esquerda seguido imediatamente por uma letra maiúscula. O escopo desses identificadores é absoluto. Por exemplo, não é possível usar o identificador **_UPPER** específico da Microsoft por esse motivo.

## <a name="see-also"></a>Consulte também

[Compatibilidade](../c-runtime-library/compatibility.md)
