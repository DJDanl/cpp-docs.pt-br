---
title: -Oi (gerar funções intrínsecas) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableIntrinsicFunctions
- /oi
- VC.Project.VCCLWCECompilerTool.EnableIntrinsicFunctions
dev_langs:
- C++
helpviewer_keywords:
- Oi compiler option [C++]
- intrinsic functions, generate
- /Oi compiler option [C++]
- -Oi compiler option [C++]
- generate intrinsic functions compiler option [C++]
ms.assetid: fa4a3bf6-0ed8-481b-91c0-add7636132b4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f28051f5d7aaaa4606fffa4d4c94fb2086031419
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="oi-generate-intrinsic-functions"></a>/Oi (gerar funções intrínsecas)
Substitui a alguma função chama com formulários intrínsecos ou outra forma especiais da função que ajudam a seu aplicativo é executado mais rapidamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Oi[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Programas que usam funções intrínsecas são mais rápidos porque não tem a sobrecarga das chamadas de função, mas pode ser maiores devido ao código adicional criado.  
  
 Consulte [intrínseco](../../preprocessor/intrinsic.md) para obter mais informações, no qual funções têm intrínsecos formulários.  
  
 **/Oi** é apenas uma solicitação para o compilador para substituir algumas chamadas de função intrínsecos; o compilador pode chamar a função (e não substitua a chamada de função com um intrínseco) se resultará em um melhor desempenho.  
  
 **x86 específico**  
  
 As funções de ponto flutuantes intrínsecas não executa nenhuma verificação especial em valores de entrada para trabalhar em intervalos restritos de entrada e ter condições de limite que as rotinas da biblioteca com o mesmo nome e de tratamento de exceção diferente. Usar os formulários intrínsecos true significa perda de tratamento de exceção do IEEE e perda de `_matherr` e `errno` funcionalidade; o último implica perda de conformidade com ANSI. No entanto, os formulários intrínsecos podem acelerar consideravelmente programas intensivos de ponto flutuante e para vários programas, os problemas de conformidade são pouco valor prático.  
  
 Você pode usar o [Za](../../build/reference/za-ze-disable-language-extensions.md) opção de compilador para substituir a geração das opções de ponto flutuantes intrínsecas true. Nesse caso, as funções são geradas como rotinas de biblioteca que passam argumentos diretamente para o chip de ponto flutuante em vez de enviá-los para a pilha do programa.  
  
 **Término x86 específico**  
  
 Você também usar [intrínseco](../../preprocessor/intrinsic.md) para criar funções intrínsecas, ou [função (C/C++)](../../preprocessor/function-c-cpp.md) forçar explicitamente uma chamada de função.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **otimização** página de propriedades.  
  
4.  Modificar o **Habilitar funções intrínsecas** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableIntrinsicFunctions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Intrínsecos do compilador](../../intrinsics/compiler-intrinsics.md)