---
title: "/O1, /O2 (minimizar tamanho, maximizar velocidade) | Microsoft Docs"
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
  - "/o2"
  - "/o1"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /O1 (C++)"
  - "Opção de compilador /O2 (C++)"
  - "código rápido"
  - "Opção de compilador maximizar velocidade [C++]"
  - "Opção de compilador minimizar tamanho [C++]"
  - "Opção de compilador O1 [C++]"
  - "Opção de compilador -O1 [C++]"
  - "Opção de compilador O2 [C++]"
  - "Opção de compilador -O2 [C++]"
  - "código pequeno"
ms.assetid: 2d1423f5-53d9-44da-8908-b33a351656c2
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /O1, /O2 (minimizar tamanho, maximizar velocidade)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Seleciona um conjunto predefinido de opções que afetam o tamanho e a velocidade de arquivos.  
  
## Sintaxe  
  
```  
/O1  
/O2  
```  
  
## Comentários  
 A tabela a seguir descreve **\/O1** e **\/O2**.  
  
|Opção|Equivalente a|Comment|  
|-----------|-------------------|-------------|  
|**\/O1** \(minimize o tamanho\)|**\/Og \/Os \/Oy \/Ob2 \/Gs \/GF \/Gy**|Cria o código o menor na maioria dos casos.|  
|**\/O2** \(maximizar a velocidade\)|**\/Og \/Oi \/Ot \/Oy \/Ob2 \/Gs \/GF \/Gy**|Cria o código o mais rápido na maioria dos casos. \(configuração padrão para construções da versão\)|  
  
 **\/O1** e **\/O2** também permitem que a otimização nomeada do valor de retorno, o que elimina o construtor de cópia e o destruidor de um valor de retorno baseado pilha.  Considere o exemplo a seguir.  A função de `Test` não criará o construtor ou o destruidor de cópia.  Adicionar instruções para o construtor de construtor, de destruidor e de cópia para ver o efeito de otimização do valor de retorno Named quando você executa o programa.  Para obter mais informações, consulte [Otimização nomeada do valor de retorno no Visual C\+\+ 2005](http://go.microsoft.com/fwlink/?linkid=131571).  
  
```  
// O1_O2_NRVO.cpp  
// compile with: /O1  
struct A {  
   A() {}  
   ~A() {}  
   A(const A& aa) {}  
};  
  
A Test() {  
   A a;  
   return a;  
}  
int main() {  
   A aa;  
   aa = Test();  
}  
```  
  
 **x86 específico**  
  
 Essas opções implicam o uso da opção de omissão de Quadro\- ponteiro[\/Oy](../../build/reference/oy-frame-pointer-omission.md)\(\).  
  
 **Específico END x86**  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Otimização** .  
  
4.  Modifique a propriedade de **Otimização** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.  
  
## Consulte também  
 [\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [\/EH \(modelo de tratamento de exceções\)](../../build/reference/eh-exception-handling-model.md)