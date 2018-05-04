---
title: -GT (armazenamento de Local de Thread seguro de fibra suporte) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableFiberSafeOptimizations
- /gt
dev_langs:
- C++
helpviewer_keywords:
- /GT compiler option [C++]
- GT compiler option [C++]
- thread-local storage
- static thread-local storage and fiber safety
- -GT compiler option [C++]
- fiber-safe static thread-local storage compiler option [C++]
ms.assetid: 071fec79-c701-432b-9970-457344133159
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 493199cf4d5e66a866fbaa87aafc4098c3114cf6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="gt-support-fiber-safe-thread-local-storage"></a>/GT (armazenamento local de thread seguro de fibra de suporte)
Dá suporte a segurança de fibra para dados alocados usando o armazenamento local de thread estático, ou seja, os dados alocados com `__declspec(thread)`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/GT  
```  
  
## <a name="remarks"></a>Comentários  
 Dados declarados com `__declspec(thread)` é referenciado por meio de uma matriz de armazenamento local de thread (TLS). A matriz TLS é uma matriz de endereços que o sistema mantém para cada thread. Cada endereço nessa matriz fornece o local dos dados de armazenamento local de thread.  
  
 Uma fibra é um objeto leve que consiste em uma pilha e um contexto de registro e pode ser agendado em vários threads. Uma fibra pode executar em qualquer thread. Como uma fibra pode obter trocada e reiniciada posteriormente em um thread diferente, o endereço da matriz de TLS não deve ser armazenado em cache ou otimizado como uma subexpressão comum em uma chamada de função (consulte o [/Og (otimizações globais)](../../build/reference/og-global-optimizations.md) opção detalhes). **/GT** impede que tais otimizações.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **otimização** página de propriedades.  
  
4.  Modificar o **habilitar otimizações de fibra segura** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFiberSafeOptimizations%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)