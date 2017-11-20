---
title: "-Os, -Ot (favorecer código pequeno, favorecer código rápido) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.FavorSizeOrSpeed
- /os
- VC.Project.VCCLCompilerTool.FavorSizeOrSpeed
dev_langs: C++
helpviewer_keywords:
- favor fast code compiler option [C++]
- /Os compiler option [C++]
- Ot compiler option [C++]
- /Ot compiler option [C++]
- small machine code
- -Ot compiler option [C++]
- fast code
- favor small code compiler option [C++]
- Os compiler option [C++]
- -Os compiler option [C++]
ms.assetid: 9a340806-fa15-4308-892c-355d83cac0f2
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 5663f71ff6e8654312e3d8c8f76d8acfd9988e3d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="os-ot-favor-small-code-favor-fast-code"></a>/Os, /Ot (favorecer código pequeno, favorecer código rápido)
Minimiza ou maximiza o tamanho de EXEs e DLLs.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Os  
/Ot  
```  
  
## <a name="remarks"></a>Comentários  
 **/Os** (favorecer código pequeno) minimiza o tamanho de EXEs e DLLs ao instruir o compilador a favorecer tamanho sobre velocidade. O compilador pode reduzir muitas construções de C e C++ para sequências funcionalmente semelhantes de código de máquina. Ocasionalmente, essas diferenças oferecem vantagens e desvantagens de tamanho versus velocidade. O **/Os** e **/Ot** opções permitem que você especifique a preferência de um em detrimento de outro:  
  
 **/OT** (favorecer rápido código) maximiza a velocidade de EXEs e DLLs ao instruir o compilador a favorecer velocidade sobre tamanho. (Esse é o padrão). O compilador pode reduzir muitas construções de C e C++ para sequências funcionalmente semelhantes de código de máquina. Ocasionalmente, essas diferenças oferecem vantagens e desvantagens de tamanho versus velocidade. A opção /Ot é indicada pela maximizar velocidade ([/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md)) opção. O **/O2** opção combina várias opções para gerar código muito rápido.  
  
 Se você usar **/Os** ou **/Ot**, em seguida, você também deve especificar [/Og](../../build/reference/og-global-optimizations.md) para otimizar o código.  
  
> [!NOTE]
>  Informações coletadas de execuções de teste de criação de perfil substituirão otimizações que estariam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, [Profile-Guided otimizações](../../build/reference/profile-guided-optimizations.md).  
  
 **x86 específico**  
  
 O exemplo de código a seguir demonstra a diferença entre a favorecer código pequeno (**/Os**) opções e o código a Favor rápida (**/Ot**) opção:  
  
> [!NOTE]
>  A seguir descreve o comportamento esperado ao usar **/Os** ou **/Ot**. No entanto, o comportamento de compilador de versão para versão pode resultar em otimizações diferentes para o código a seguir.  
  
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
  
 Conforme mostrado no fragmento de código de máquina abaixo, quando DIFFER.c é compilado para o tamanho (**/Os**), o compilador implementa o multiplicar expressão na instrução de retorno explicitamente como um múltiplo para produzir uma sequência curta e mais lenta de código:  
  
```  
mov    eax, DWORD PTR _x$[ebp]  
imul   eax, 71                  ; 00000047H  
```  
  
 Como alternativa, quando DIFFER.c é compilado pela velocidade (**/Ot**), o compilador implementa o multiplicar expressão na instrução de retorno como uma série de shift e `LEA` instruções para produzir uma sequência, mas mais rápida de código:  
  
```  
mov    eax, DWORD PTR _x$[ebp]  
mov    ecx, eax  
shl    eax, 3  
lea    eax, DWORD PTR [eax+eax*8]  
sub    eax, ecx  
```  
  
 **Término x86 específico**  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **otimização** página de propriedades.  
  
4.  Modificar o **favorecer tamanho ou velocidade** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.FavorSizeOrSpeed%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)