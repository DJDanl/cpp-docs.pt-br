---
title: "/Os, /Ot (favorecer c&#243;digo pequeno, favorecer c&#243;digo r&#225;pido) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.FavorSizeOrSpeed"
  - "/os"
  - "VC.Project.VCCLCompilerTool.FavorSizeOrSpeed"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Os (C++)"
  - "Opção de compilador /Ot (C++)"
  - "código rápido"
  - "Opção de compilador prefira código veloz [C++]"
  - "Opção de compilador favoreça código pequeno [C++]"
  - "Opção de compilador Os [C++]"
  - "Opção de compilador -Os [C++]"
  - "Opção de compilador Ot [C++]"
  - "Opção de compilador -Ot [C++]"
  - "código de máquina pequeno"
ms.assetid: 9a340806-fa15-4308-892c-355d83cac0f2
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Os, /Ot (favorecer c&#243;digo pequeno, favorecer c&#243;digo r&#225;pido)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Minimiza ou maximiza o tamanho de Execuções e da DLL.  
  
## Sintaxe  
  
```  
/Os  
/Ot  
```  
  
## Comentários  
 **\/Os** código \(pequeno\) em detrimento minimiza o tamanho de Execuções e de DLL instruindo o compilador favorecem o tamanho sobre a velocidade.  O compilador pode reduzir muitas construções de 2.0 C e C\+\+ funcional semelhantes às sequências de código de máquina.  Ocasionalmente essas diferenças oferecem troca de tamanho na velocidade.  As opções de **\/Os** e de **\/Ot** lhe permitem especificar uma preferência para uma sobre a outro:  
  
 **\/Ot** \(código rápido em detrimento\) maximiza a velocidade de Execuções e de DLL instruindo o compilador para favorecer a velocidade sobre o tamanho. \(Essa é a opção.\) O compilador pode reduzir muitas construções de 2.0 C e C\+\+ funcional semelhantes às sequências de código de máquina.  Ocasionalmente, essas diferenças oferecem troca de tamanho na velocidade.  A opção \/Ot é insinuada pela opção de velocidade maximizar[\/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md)\(\).  A opção de **\/O2** combina várias opções gerar código muito rápida.  
  
 Se você usar **\/Os** ou **\/Ot**, você também deve especificar [\/Og](../../build/reference/og-global-optimizations.md) para otimizar o código.  
  
> [!NOTE]
>  As informações coletadas de analisar execuções de teste substituirá as otimizações que seriam de outra forma aplicado se você especificar **\/Ob**, **\/Os**, ou **\/Ot**.  Para obter mais informações, consulte [Otimizações orientadas a perfil](../../build/reference/profile-guided-optimizations.md).  
  
 **x86 específico**  
  
 O código de exemplo a seguir demonstra a diferença entre as opções pequenas de código de suporte \(**\/Os**\) e o suporte codificar rapidamente a opção \(de**\/Ot**\):  
  
> [!NOTE]
>  A tabela a seguir descreve o comportamento esperado ao usar **\/Os** ou **\/Ot**.  Porém, o comportamento do compilador de versão para versão pode resultar em otimizações diferentes para o código abaixo.  
  
```  
/* differ.c  
  This program implements a multiplication operator  
  Compile with /Os to implement multiply explicitly as multiply.  
  Compile with /Ot to implement as a series of shift and LEA instructions.  
*/  
int differ(int x)  
{  
    return x * 71;  
}  
```  
  
 Conforme mostrado no fragmento de código de máquina em, quando DIFFER.c será criado para o tamanho \(**\/Os**\), o compilador implementa a expressão de multiplicação na instrução de retorno explicitamente como uma multiplicação para gerar uma sequência curto mas mais lenta de código:  
  
```  
mov    eax, DWORD PTR _x$[ebp]  
imul   eax, 71                  ; 00000047H  
```  
  
 Como alternativa, quando DIFFER.c estiver sendo compilado para a velocidade**\/Ot**\(\), o implementa do compilador a expressão de multiplicação na instrução de retorno como uma série de turno e instruções de `LEA` gerar uma sequência rápido e mais longa de código:  
  
```  
mov    eax, DWORD PTR _x$[ebp]  
mov    ecx, eax  
shl    eax, 3  
lea    eax, DWORD PTR [eax+eax*8]  
sub    eax, ecx  
```  
  
 **Específico END x86**  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Otimização** .  
  
4.  Modifique a propriedade de **Favoreça Tamanho Ou Velocidade** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.FavorSizeOrSpeed%2A>.  
  
## Consulte também  
 [\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)