---
title: "-Diagnóstico (opções do compilador diagnósticas) | Microsoft Docs"
ms.custom: 
ms.date: 11/11/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /diagnostics
- VC.Project.VCCLCompilerTool.DiagnosticsFormat
dev_langs:
- C++
helpviewer_keywords:
- /diagnostics compiler diagnostic options [C++]
- -diagnostics compiler diagnostic options [C++]
- diagnostics compiler diagnostic options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1a1c893b530bfa895e5ec127bd0aea2fb0df4ff3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="diagnostics-compiler-diagnostic-options"></a>/Diagnostics (opções do compilador diagnósticas)  
  
Use o **/diagnostics** opção de compilador para especificar a exibição de informações de local de erro e aviso.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/diagnostics:{caret|classic|column}
```  

## <a name="remarks"></a>Comentários  
O **/diagnostics** opção de compilador controla a exibição de informações de aviso e erro.  
  
O **/diagnostics:classic** é a opção padrão, que informa apenas o número de linha em que o problema foi encontrado.  
  
O **/diagnostics:column** opção também inclui a coluna onde o problema foi encontrado. Isso pode ajudá-lo a identificar a construção de idioma específico ou o caractere que está causando o problema.  
  
O **/diagnostics:caret** opção inclui a coluna em que o problema foi encontrado e coloca um acento circunflexo (^) no local na linha do código onde o problema foi detectado.  
  
Observe que em alguns casos, o compilador não detecta um problema em que ele ocorreu. Por exemplo, um ponto e vírgula ausente pode não ser detectado até que outros, inesperados símbolos foram encontrados. A coluna é informada e o cursor é colocado em que o compilador detectado que algo estava errado, o que nem sempre é aqui que você precisa fazer a correção.  
  
O **/diagnostics** opção está disponível a partir do Visual Studio de 2017.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1. Abra seu projeto **páginas de propriedade** caixa de diálogo.   
  
2. Em **propriedades de configuração**, expanda o **C/C++** pasta e escolha o **geral** página de propriedades.  
  
3. Use o controle de lista suspensa no **formato diagnóstico** opção de exibição do campo para selecionar um diagnóstico. Escolha **Okey** ou **aplicar** para salvar suas alterações.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)