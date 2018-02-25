---
title: '#Diretivas de ifdef e #ifndef (C/C++) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- '#ifndef'
- '#ifdef'
dev_langs:
- C++
helpviewer_keywords:
- '#ifdef directive'
- preprocessor, directives
- ifdef directive (#ifdef)
- ifndef directive (#ifndef)
- '#ifndef directive'
ms.assetid: 2b0be69d-9e72-45d8-8e24-e4130fb2455b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a8f1a10e9d8437b71591efc9ce2915c9f485e0c4
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ifdef-and-ifndef-directives-cc"></a>Diretivas #ifdef e #ifndef (C/C++)
O **#ifdef** e **#ifndef** diretivas de executam a mesma tarefa como o `#if` diretiva quando ele é usado com **definido**( *identificador* ).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#ifdef identifier  
#ifndef identifier  
  
// equivalent to  
#if defined identifier  
#if !defined identifier  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o **#ifdef** e **#ifndef** diretivas em qualquer lugar `#if` pode ser usado. O **#ifdef** *identificador* instrução é equivalente a `#if 1` quando *identificador* tiver sido definida, e é equivalente a `#if 0` quando *identificador* não foi definido ou não tem sido definida com o `#undef` diretiva. Essas políticas verificam somente a presença ou ausência de identificadores definidos com `#define`, não para identificadores declarados no código-fonte C ou C++.  
  
 Essas políticas são fornecidas somente para compatibilidade com versões anteriores da linguagem. O **definido (** *identificador* **)** expressão constante usada com a `#if` diretiva é preferencial.  
  
 O **#ifndef** diretiva verifica o oposto da condição verificada pelo **#ifdef**. Se o identificador não foi definido (ou a definição foi removida com `#undef`), a condição é true (diferente de zero). Caso contrário, a condição será false (0).  
  
 **Seção específica da Microsoft**  
  
 O *identificador* podem ser passados na linha de comando usando a opção /D. Até 30 macros podem ser especificadas com /D.  
  
 Isso é útil para verificar se uma definição existe, uma vez que uma definição pode ser passada da linha de comando. Por exemplo:  
  
```  
// ifdef_ifndef.CPP  
// compile with: /Dtest /c  
#ifndef test  
#define final  
#endif  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)