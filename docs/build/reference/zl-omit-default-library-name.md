---
title: "-Zl (omitir nome da biblioteca padrão) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /zi
- VC.Project.VCCLCompilerTool.OmitDefaultLibName
dev_langs: C++
helpviewer_keywords:
- -Zl compiler option [C++]
- ZI compiler option
- Omit Default Library Name compiler option
- /Zl compiler option [C++]
- default libraries, omitting names
ms.assetid: b27d39d0-44d6-498c-84ae-27c1326fee59
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2b77b9c1033be1f6144d92b6051118ca85aaaf20
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zl-omit-default-library-name"></a>/Zl (omitir nome da biblioteca padrão)
Omite o nome da biblioteca padrão C em tempo de execução do arquivo. obj. Por padrão, o compilador coloca o nome da biblioteca no arquivo .obj para direcionar o vinculador à biblioteca correta.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zl  
```  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre a biblioteca padrão, consulte [usar a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md).  
  
 Você pode usar **/Zl** para compilar arquivos. obj você planeja colocar em uma biblioteca. Embora omitir o nome da biblioteca salva apenas uma pequena quantidade de espaço para um arquivo. obj único, o espaço total salvo é significativo em uma biblioteca que contém muitos módulos de objeto.  
  
 Essa opção é uma opção avançada. Definir essa opção remove certo suporte de biblioteca de tempo de execução do C que pode ser exigido pelo seu aplicativo, resultando em erros de tempo de vinculação, se seu aplicativo depende esse suporte. Se você usar essa opção, você deve fornecer os componentes necessários de alguma outra maneira.  
  
 Use [/NODEFAULTLIB (ignorar bibliotecas)](../../build/reference/nodefaultlib-ignore-libraries.md). para direcionar o vinculador para ignorar as referências de biblioteca em todos os arquivos. obj.  
  
 Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
 Ao compilar com **/Zl**, `_VC_NODEFAULTLIB` está definido.  Por exemplo:  
  
```  
// vc_nodefaultlib.cpp  
// compile with: /Zl  
void Test() {  
   #ifdef _VC_NODEFAULTLIB  
      int i;  
   #endif  
  
   int i;   // C2086  
}  
```  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **avançado** página de propriedades.  
  
4.  Modificar o **omitir nomes de biblioteca padrão** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitDefaultLibName%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)