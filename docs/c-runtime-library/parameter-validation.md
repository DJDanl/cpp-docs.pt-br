---
title: "Validação de parâmetro | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: parameters, validation
ms.assetid: 019dd5f0-dc61-4d2e-b4e9-b66409ddf1f2
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 01d200e716ce4291350584ac7e2f388cca30cedf
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="parameter-validation"></a>Validação do parâmetro
A maioria das funções de CRT com segurança aprimorada e muitas das funções preexistentes validam seus parâmetros. Isso pode incluir verificar se há ponteiros nulos, verificar se os inteiros estão dentro de um dado alcance ou verificar se os valores de enumeração são válidos. Quando um parâmetro inválido é encontrado, o manipulador de parâmetro inválido é executado.  
  
## <a name="invalid-parameter-handler-routine"></a>Rotina do manipulador de parâmetro inválido  
 Quando uma função da Biblioteca de Tempo de Execução C detecta um parâmetro inválido, ela captura algumas informações sobre o erro e chama uma macro que encapsula uma função de expedição de manipulador de parâmetro inválido, um dentre [_invalid_parameter](../c-runtime-library/reference/invalid-parameter-functions.md), [_invalid_parameter_noinfo](../c-runtime-library/reference/invalid-parameter-functions.md) ou [_invalid_parameter_noinfo_noreturn](../c-runtime-library/reference/invalid-parameter-functions.md). A função de expedição chamada depende se o código é, respectivamente, um build de depuração, um build comercial ou se o erro não é considerado recuperável. 
 
 Em Builds de depuração, o macro de parâmetro inválido geralmente gera uma asserção com falha e um ponto de interrupção do depurador antes da função de expedição ser chamada. Quando o código é executado, a asserção pode ser relatada para o usuário em uma caixa de diálogo que contém “Cancelar”, “Repetir” e “Continuar” ou opções semelhantes, dependendo da versão da biblioteca de tempo de execução e do sistema operacional. Essas opções permitem ao usuário terminar imediatamente o programa, anexar um depurador ou permitir que o código existente continue em execução, o que chama a função de expedição. 
 
 A função de expedição do manipulador de parâmetro inválido por sua vez chama o manipulador de parâmetro inválido atribuído no momento. Por padrão, o parâmetro inválido chama `_invoke_watson`, fazendo com que o aplicativo “falhe”, ou seja, termine e gere um minidespejo. Se habilitada pelo sistema operacional, uma caixa de diálogo pergunta ao usuário se deseja carregar o despejo de memória para a Microsoft para análise.   
  
 Esse comportamento pode ser alterado usando as funções [_set_invalid_parameter_handler](../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) ou [_set_thread_local_invalid_parameter_handler](../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) para definir o manipulador de parâmetro inválido para a sua própria função. Se a função que você especificar não terminar o aplicativo, o controle será retornado para a função que recebeu os parâmetros inválidos. No CRT, essas funções normalmente interrompem a execução de funções, definem `errno` para um código de erro e retornam um código de erro. Em muitos casos, o valor `errno` e o valor retornado são ambos `EINVAL`, indicando um parâmetro inválido. Em alguns casos, um código de erro mais específico é retornado, tal como `EBADF` para um ponteiro de arquivo inválido passado como um parâmetro. Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="see-also"></a>Consulte também  
 [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md)   
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)