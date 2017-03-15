---
title: "/H (restringir comprimento de nomes externos) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/h"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /H (C++)"
  - "nomes externos"
  - "Opção de compilador H [C++]"
  - "Opção de compilador -H [C++]"
  - "comprimento de nome público"
ms.assetid: de701dd3-ed04-4c88-8195-960d2520ec2e
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /H (restringir comprimento de nomes externos)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Restringe o comprimento dos nomes externos.  
  
## Sintaxe  
  
```  
/Hnumber  
```  
  
## Arguments  
 `number`  
 Especifica o comprimento máximo dos nomes externos permitidos em um programa.  
  
## Comentários  
 Por padrão, o comprimento dos nomes públicos \(\) externas é 2.047 caracteres.  Isso é verdadeiro para programas de 2.0 C e C\+\+.  Usar **\/H** só pode diminuir o máximo de comprimento máximo permitido dos identificadores, não pode aumentar o.  Um espaço entre **\/H** e `number` é opcional.  
  
 Se um programa contém nomes externos por mais tempo que `number`, os caracteres adicionais serão ignorados.  Se você criar um programa sem **\/H** e se um identificador contiver mais de 2.047 caracteres, o compilador gerará [Erro fatal C1064](../Topic/Fatal%20Error%20C1064.md).  
  
 O limite no comprimento inclui qualquer principal completo criado sublinhado \(\_\) ou sinal arroba \(@\).  Esses caracteres são parte do identificador e têm um local significativo.  
  
-   O compilador adiciona um principal sublinhado \(\_\) com os nomes alterados por `__cdecl` \(padrão\) e por `__stdcall` que chama as convenções, e um sinal de arroba \(@\) principal para nomes alterados por `__fastcall` chamando a convenção.  
  
-   O compilador acrescenta informações de tamanho do argumento para nomes alterados por `__fastcall` e por `__stdcall` que chama convenções, e adiciona informações de tipo para nomes C\+\+.  
  
 Você pode localizar **\/H** útil:  
  
-   Quando você criar programas mista o idioma ou portáteis.  
  
-   Quando você usar as ferramentas que limitam o comprimento de identificadores externos.  
  
-   Quando você quiser restringir a quantidade de espaço que usam símbolos em uma compilação de depuração.  
  
 O exemplo a seguir mostra como usar **\/H** pode realmente introduzir erros se os comprimentos de identificador delimitados são muito:  
  
```  
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
  
 Você também deve ter cuidado ao usar a opção de **\/H** devido aos identificadores predefinidos do compilador.  Se o comprimento máximo do identificador for muito pequeno, alguns identificadores predefinidos serão chamadas de função não resolvidas bem como determinadas na biblioteca.  Por exemplo, se a função de `printf` é usada e a opção **\/H5** está especificado em tempo de compilação, o símbolo **\_prin** será criado para referenciar `printf`, e isso não será localizada na biblioteca.  
  
 O uso de **\/H** é incompatível com [\/GL \(otimização de todo o programa\)](../../build/reference/gl-whole-program-optimization.md).  
  
 **\/H** é substituído; os limites de comprimento máximo foram gerados e **\/H** não é mais necessário.  Para obter mais informações, consulte [Deprecated Compiler Options in Visual C\+\+ 2005](http://msdn.microsoft.com/pt-br/aa59fce3-50b8-4f66-9aeb-ce09a7a84cce).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção do compilador na caixa de **Opções Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)