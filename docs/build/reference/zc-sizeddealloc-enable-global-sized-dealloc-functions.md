---
title: "/ZC:sizedDealloc (habilitar dimensionado desalocação funções globais) | Microsoft Docs"
ms.custom: 
ms.date: 12/13/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- sizedDealloc
- /Zc:sizedDealloc
dev_langs:
- C++
helpviewer_keywords:
- -Zc compiler options (C++)
- sizedDealloc
- Enable Global Sized Deallocation Functions
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 3a73ace0-4d36-420a-b699-0ca6fc0dd134
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1343c037f87aee609de2b082cb87f7f1f2832221
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcsizeddealloc-enable-global-sized-deallocation-functions"></a>/ZC:sizedDealloc (habilitar dimensionado desalocação funções globais)  
O `/Zc:sizedDealloc` opção de compilador informa ao compilador para chamar preferencialmente global `operator delete` ou `operator delete[]` funções que têm um segundo parâmetro do tipo `size_t` quando o tamanho do objeto está disponível. Essas funções podem usar o `size_t` parâmetro para otimizar o desempenho de desalocador.   
  
## <a name="syntax"></a>Sintaxe  
`/Zc:sizedDealloc`[`-`\]  
  
## <a name="remarks"></a>Comentários  
  
11 C++ padrão, você pode definir funções de membro estático `operator delete` e `operator delete[]` que levam a um segundo `size_t` parâmetro. Normalmente, eles são usados em combinação com [operador novo](../../cpp/new-operator-cpp.md) funções para implementar mais eficiente alocadores e deallocators para o objeto. No entanto, o C++ 11 não definiu um conjunto equivalente de funções de desalocação no escopo global. No C++ 11, desalocação global funções que têm um segundo parâmetro do tipo `size_t` são considerados funções de exclusão de posicionamento. Ele devem ser chamados explicitamente passando um argumento de tamanho.  
  
C + + 14 padrão altera o comportamento do compilador. Quando você define global `operator delete` e `operator delete[]` que levam a um segundo parâmetro do tipo `size_t`, o compilador prefere chamar essas funções quando as versões de escopo de membro não são invocadas e o tamanho do objeto está disponível. O compilador passa o argumento de tamanho implicitamente. As versões de único argumento são chamadas quando o compilador não pode determinar o tamanho do objeto que está sendo desalocado. Caso contrário, as regras habituais para escolher a versão da função de desalocação invocar ainda se aplicam. Chamadas para as funções globais podem ser especificadas explicitamente, acrescentando o operador de resolução do escopo (`::`) para a chamada de função de desalocação.  
  
Por padrão, o Visual C++ a partir do Visual Studio 2015 implementa esse C + + 14 o comportamento padrão. Você pode especificar isso explicitamente, definindo o `/Zc:sizedDealloc` opção de compilador. Isso representa uma quebra potencialmente alteração. Use o `/Zc:sizedDealloc-` opção para preservar o comportamento antigo, por exemplo, quando seu código define operadores de exclusão de posicionamento que usam um segundo parâmetro do tipo `size_t`. As implementações padrão de biblioteca do Visual Studio de funções de desalocação global com o segundo parâmetro do tipo `size_t` chamar as versões de parâmetro único. Se seu código fornece o único parâmetro único global delete operador e operador delete [], as implementações padrão de biblioteca das funções de desalocação dimensionada global invocar funções globais.  
  
Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).  
  
## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
2.  Do **configurações** menu suspenso, escolha **todas as configurações de**.  
3.  Selecione o **propriedades de configuração**, **C/C++**, **linha de comando** página de propriedades.  
4.  Modificar o **opções adicionais** propriedade incluir `/Zc:sizedDealloc` ou `/Zc:sizedDealloc-` e, em seguida, escolha **Okey**.  
  
## <a name="see-also"></a>Consulte também  
[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
[/ZC (conformidade)](../../build/reference/zc-conformance.md)  
