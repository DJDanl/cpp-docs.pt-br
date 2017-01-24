---
title: "/Zc:forScope (for&#231;ar conformidade para escopo de loop) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.ForceConformanceInForLoopScope"
  - "VC.Project.VCCLWCECompilerTool.ForceConformanceInForLoopScope"
  - "/zc:forScope"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opções do compilador /Zc [C++]"
  - "Opções de compilador de conformidade"
  - "opções de compilador Zc [C++]"
  - "opções de compilador -Zc [C++]"
ms.assetid: 3031f02d-3b14-4ad0-869e-22b0110c3aed
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zc:forScope (for&#231;ar conformidade para escopo de loop)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para implementar o comportamento padrão do C\+\+ para [para](../../cpp/for-statement-cpp.md) loops com extensões da Microsoft \([\/Ze](../../build/reference/za-ze-disable-language-extensions.md)\).**\/ZC: forScope** é ativada por padrão.  
  
## Sintaxe  
  
```  
/Zc:forScope[-]  
```  
  
## Comentários  
 O **\/Zc:forScope\-** opção é preterida e será removida em uma versão futura. Uso de **\/Zc:forScope\-** gera um aviso D9035 de substituição.  
  
 Comportamento padrão é permitir que um **para** inicializador do loop saem do escopo após o **para** loop. Em **\/Zc:forScope\-** e [\/Ze](../../build/reference/za-ze-disable-language-extensions.md), o **para** inicializador do loop permanece no escopo até que o escopo local terminar.  
  
 O código a seguir compila em **\/Ze** mas não em **\/Za**:  
  
```cpp  
// zc_forScope.cpp  
// compile by using: cl /Zc:forScope- /Za zc_forScope.cpp  
// C2065, D9035 expected  
int main() {  
    // Compile by using cl /Zc:forScope- zc_forScope.cpp  
    // to compile this non-standard code as-is.  
    // Uncomment the following line to resolve C2065 for /Za.  
    // int i;  
    for (int i = 0; i < 1; i++)  
        ;  
    i = 20;   // i has already gone out of scope under /Za  
}  
```  
  
 Se você usar **\/Zc:forScope\-**, aviso C4288 \(desativado por padrão\) é gerado se uma variável está no escopo devido a uma declaração que foi feita em um escopo anterior. Para demonstrar isso, remova o `//` caracteres no código de exemplo para declarar `int i`.  
  
 Você pode modificar o comportamento de tempo de execução de **\/ZC: forScope** usando o [conform](../../preprocessor/conform.md) pragma.  
  
 Se você usar **\/Zc:forScope\-** em um projeto que tem um arquivo. pch existente, um aviso será gerado, **\/Zc:forScope\-** é ignorado, e a compilação continua usando os arquivos. pch existentes. Se você quiser um novo arquivo. pch gerado, use [\/Yc \(criar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yc-create-precompiled-header-file.md).  
  
 Para obter mais informações sobre problemas de conformidade no Visual C\+\+, consulte [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md).  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel de navegação, abra a **Propriedades de configuração**, **C\/C\+\+**, **idioma** página de propriedades.  
  
3.  Modificar o **Forçar conformidade para escopo de Loop** propriedade.  
  
### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ForceConformanceInForLoopScope%2A>.  
  
## Consulte também  
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)   
 [\/Za, \/Ze \(desabilitar extensões de linguagem\)](../../build/reference/za-ze-disable-language-extensions.md)