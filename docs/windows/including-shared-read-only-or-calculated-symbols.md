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
- symbols [C++], read-only
- symbols [C++], shared
- symbols [C++], calculated
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
ms.openlocfilehash: 329f1d21489b57130531db20014e249588f101a6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46400504"
---
# <a name="including-shared-read-only-or-calculated-symbols"></a>Incluindo símbolos compartilhados (somente leitura) ou calculados

Na primeira vez em que o ambiente de desenvolvimento lê um arquivo de recurso criado por outro aplicativo, ele marca todos os arquivos de cabeçalho incluídos como somente leitura. Posteriormente, você pode usar o [caixa de diálogo recurso inclui](../windows/resource-includes-dialog-box.md) para adicionar arquivos de cabeçalho de símbolo somente leitura adicionais.

Um motivo que você talvez queira usar definições de símbolo somente leitura é para arquivos de símbolo que você planeja compartilhar entre vários projetos.

Você também pode usar arquivos de símbolo incluídos quando você tiver recursos existentes com as definições de símbolo que usam expressões em vez de inteiros simples para definir o valor de símbolo. Por exemplo:

```cpp
#define   IDC_CONTROL1 2100
#define   IDC_CONTROL2 (IDC_CONTROL1+1)  
```

O ambiente será interprete corretamente esses símbolos calculados, desde que:

- Os símbolos calculados são colocados em um arquivo de símbolos somente leitura.

- Seu arquivo de recursos contém recursos aos quais esses símbolos calculados já estão atribuídos.

- Uma expressão numérica é esperada.

> [!NOTE]
> Se uma cadeia de caracteres ou uma expressão numérica é esperada, a expressão não é avaliada.

### <a name="to-include-shared-read-only-symbols-in-your-resource-file"></a>Para incluir símbolos compartilhados de (somente leitura) no seu arquivo de recurso

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha [recurso inclui](../windows/resource-includes-dialog-box.md) no menu de atalho.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No **diretivas de símbolo somente leitura** caixa, use o `#include` diretiva do compilador para especificar o arquivo onde você deseja que os símbolos somente leitura sejam mantidos.

   Não chame o arquivo `Resource.h`, já que é o nome de arquivo normalmente usado pelo arquivo de cabeçalho de símbolo principal.

   > [!NOTE]
   > **Importante** o que você digita na caixa de diretivas de símbolo somente leitura está incluído no arquivo de recurso exatamente conforme você o digita. Certifique-se de que você digitou não contém erros de ortografia ou de sintaxe.

   Use o **diretivas de símbolo somente leitura** caixa para incluir arquivos com apenas definições de símbolo. Não inclua as definições de recurso. Caso contrário, as definições de recurso duplicado serão criadas quando o arquivo é salvo.

3. Coloque os símbolos no arquivo especificado por você.

   Os símbolos nos arquivos incluídos dessa maneira são avaliados sempre que você abrir o arquivo de recurso, mas elas não são substituídas no disco quando você salvar o arquivo.

4. Clique em **OK**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Restrições de nome de símbolo](../windows/symbol-name-restrictions.md)<br/>
[Restrições de valor de símbolo](../windows/symbol-value-restrictions.md)<br/>
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)<br/>
[Símbolos: identificadores de recursos](../windows/symbols-resource-identifiers.md)