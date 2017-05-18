---
title: Aviso LNK4210 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4210
dev_langs:
- C++
helpviewer_keywords:
- LNK4210
ms.assetid: db48cff8-a2be-4a77-8d03-552b42c228fa
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 127d4bdc85d07468f91656bc0aff5f4f2d015df5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4210"></a>Aviso LNK4210 (Ferramentas de Vinculador)
existe uma seção; Há podem ser sem tratamento inicializadores estáticos ou terminadores  
  
 Alguns códigos introduziu inicializadores estáticos ou terminadores, mas o CRT ou equivalente (que precisa executar o inicializadores estáticos ou terminadores) não é executado quando o aplicativo for iniciado. Exemplos de código que causa isso:  
  
-   Variável de classe global com um construtor, destruidor ou tabela de função virtual.  
  
-   Variável global inicializado com uma constante de tempo de compilação não.  
  
 Para corrigir esse problema, tente um destes procedimentos:  
  
-   Remova todos os códigos com inicializadores estáticos.  
  
-   Não use [/NOENTRY](../../build/reference/noentry-no-entry-point.md).  Depois de remover /NOENTRY, você também precisa adicionar MSVCRT, libcmt ou Libcmtd para sua linha de comando do vinculador.  
  
-   Adicione MSVCRT, libcmt ou Libcmtd para sua linha de comando do vinculador.  
  
-   Ao mover do /clr: pura compilação /clr, remova o [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opção da linha de vinculador. Isso permitirá a inicialização de CRT, permitindo que os inicializadores de estáticos ser executado na inicialização do aplicativo.  
  
-   Se o projeto é construído com [/ENTRY](../../build/reference/entry-entry-point-symbol.md), e se /ENTRY é passado a uma função diferente de `_DllMainCRTStartup`, a função deve chamar CRT_INIT. Consulte [comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md) e o artigo da Base de dados de Conhecimento Q94248, [http://support.microsoft.com/default.aspx?scid=kb;en-us;94248](http://support.microsoft.com/default.aspx?scid=kb;en-us;94248) para obter mais informações.  
  
 O [/GS](../../build/reference/gs-buffer-security-check.md) opção de compilador requer o código de inicialização do CRT.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
