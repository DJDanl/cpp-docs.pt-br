---
title: -H (restringir comprimento de nomes externos) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /h
dev_langs: C++
helpviewer_keywords:
- public name length
- /H compiler option [C++]
- H compiler option [C++]
- external names
- -H compiler option [C++]
ms.assetid: de701dd3-ed04-4c88-8195-960d2520ec2e
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1a69bf1b4e6b2e552bd73594a2c33f092570b94c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="h-restrict-length-of-external-names"></a>/H (restringir comprimento de nomes externos)
Preterido. Restringe o comprimento de nomes externos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Hnumber  
```  
  
## <a name="arguments"></a>Arguments  
 `number`  
 Especifica o comprimento máximo de nomes externos permitido em um programa.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, o comprimento de nomes (públicos) externos é 2.047 caracteres. Isso é verdadeiro para programas C e C++. Usando **/H** pode diminuir somente o comprimento máximo permitido de identificadores, não aumentá-lo. Um espaço entre **/H** e `number` é opcional.  
  
 Se um programa contém nomes externos mais de `number`, os caracteres extras são ignorados. Se você compilar um programa sem **/H** e se um identificador contiver mais de 2.047 caracteres, o compilador gerará [C1064 de Erro Fatal](../../error-messages/compiler-errors-1/fatal-error-c1064.md).  
  
 O limite no tamanho inclui qualquer criado pelo compilador à esquerda caractere de sublinhado (_) ou sinal de arroba (@). Esses caracteres são parte do identificador e levar a um local significativo.  
  
-   O compilador adiciona um caractere de sublinhado (_) à esquerda para nomes modificados pelo `__cdecl` (padrão) e `__stdcall` convenções de chamada e um prefixo de sinal de arroba (@) para nomes modificados pelo `__fastcall` convenção de chamada.  
  
-   O compilador anexa informações de tamanho de argumento para nomes modificados pelo `__fastcall` e `__stdcall` convenções de chamada e adiciona informações de tipo para nomes de C++.  
  
 Você pode encontrar **/H** úteis:  
  
-   Quando você cria programas de linguagem mista ou portátil.  
  
-   Quando você usa ferramentas que limitam o tamanho dos identificadores externos.  
  
-   Quando você quiser restringir a quantidade de espaço que usam símbolos em uma compilação de depuração.  
  
 A exemplo a seguir mostra como usar **/H** realmente pode introduzir erros se comprimentos de identificador são muito limitados:  
  
```cpp  
// compiler_option_H.cpp  
// compile with: /H5  
// processor: x86  
// LNK2005 expected  
void func1(void);  
void func2(void);  
  
int main() { func1(); }  
  
void func1(void) {}  
void func2(void) {}  
```  
  
 Você também deve ter cuidado ao usar o **/H** opção devido a identificadores de compilador predefinidos. Se o comprimento máximo do identificador é muito pequeno, determinados identificadores predefinidos serão chamadas de função de biblioteca não resolvidas, bem como certas. Por exemplo, se o `printf` função é usada e a opção **/H5** é especificado em tempo de compilação, o símbolo **_prin** será criado para referenciar `printf`, e isso não será encontrado na biblioteca.  
  
 O uso de **/H** é incompatível com [/GL (otimização de programa total)](../../build/reference/gl-whole-program-optimization.md).  
  
 O **/H** opção foi preterida desde o Visual Studio 2005; os limites de comprimento máximo aumentaram e **/H** não é mais necessário. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções do compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)