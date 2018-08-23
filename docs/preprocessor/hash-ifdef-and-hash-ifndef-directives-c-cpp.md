---
title: '#Diretivas de # ifdef e #ifndef (C/C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8c3453cd652401e9d1f4573bb1750773cbefe8d9
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42540131"
---
# <a name="ifdef-and-ifndef-directives-cc"></a>Diretivas #ifdef e #ifndef (C/C++)
O **#ifdef** e **#ifndef** diretivas de executam a mesma tarefa como o `#if` diretiva quando ele é usado com **definidas**( *identificador* ).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#ifdef identifier  
#ifndef identifier  
  
// equivalent to  
#if defined identifier  
#if !defined identifier  
```  
  
## <a name="remarks"></a>Comentários  
 
Você pode usar o **#ifdef** e **#ifndef** diretivas em qualquer lugar `#if` pode ser usado. O **#ifdef** *identificador* instrução é equivalente a `#if 1` quando *identificador* tiver sido definida, e é equivalente a `#if 0` quando *identificador* não foi definida ou tiver sido indefinido com a `#undef` diretiva. Essas políticas verificam somente a presença ou ausência de identificadores definidos com `#define`, não para identificadores declarados no código-fonte C ou C++.  
  
Essas políticas são fornecidas somente para compatibilidade com versões anteriores da linguagem. O **definidos (** *identificador* **)** expressão constante usada com o `#if` diretiva é preferencial.  
  
O **#ifndef** diretiva verifica o oposto da condição verificada por **#ifdef**. Se o identificador não foi definido (ou a definição foi removida com `#undef`), a condição é true (diferente de zero). Caso contrário, a condição será false (0).  
  
**Seção específica da Microsoft**  
  
O *identificador* podem ser passados de linha de comando usando o `/D` opção. Até 30 macros pode ser especificado com `/D`.  
  
Isso é útil para verificar se uma definição existe, uma vez que uma definição pode ser passada da linha de comando. Por exemplo:  
  
```cpp  
// ifdef_ifndef.CPP  
// compile with: /Dtest /c  
#ifndef test  
#define final  
#endif  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 
[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)