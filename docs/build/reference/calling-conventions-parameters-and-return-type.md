---
title: Convenções de chamada, parâmetros e tipo de retorno | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- calling conventions, helper functions
- helper functions, calling conventions
- helper functions, return types
ms.assetid: 0ffa4558-6005-4803-be95-7a8ec8837660
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 077064b25f41648231f27085236fa13d1a662440
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44110611"
---
# <a name="calling-conventions-parameters-and-return-type"></a>Convenções de chamada, parâmetros e tipo de retorno

O protótipo de rotina do auxiliar é:

```
FARPROC WINAPI __delayLoadHelper2(
    PCImgDelayDescr pidd,
    FARPROC * ppfnIATEntry
);
```

### <a name="parameters"></a>Parâmetros

*pidd*<br/>
Um ponteiro para `const` um `ImgDelayDescr` (consulte delayimp.h) que contém os deslocamentos de vários dados relacionados à importação, um carimbo de data/hora para associar informações e um conjunto de atributos que fornece mais informações sobre o conteúdo do descritor. No momento, há apenas um atributo, `dlattrRva`, que indica que os endereços do descritor estão relacionados a endereços virtuais (ao contrário dos endereços virtuais).

A definição do `PCImgDelayDescr` estrutura, consulte [definições de estrutura e constante](../../build/reference/structure-and-constant-definitions.md).

*ppfnIATEntry*<br/>
Um ponteiro para o slot na IAT (tabela de endereço de importação) de carregamento atrasado a ser atualizado com o endereço da função importada. A rotina do auxiliar deve armazenar o mesmo valor que estiver retornando para esse local.

## <a name="expected-return-values"></a>Valores de retorno esperados

Se a função tiver êxito, ela retornará o endereço da função importada.

Se a função falhar, ela gerará uma exceção e retornará 0. Há três tipos de exceções possíveis:

- Parâmetro inválido, que acontece quando os parâmetros presentes em `pidd` não são especificados corretamente.

- `LoadLibrary` falhou na DLL (biblioteca de vínculo dinâmico) especificada.

- Falha de `GetProcAddress`.

Você é responsável por gerenciar essas exceções.

## <a name="remarks"></a>Comentários

A convenção de chamada da função do auxiliar é `__stdcall`. O tipo de valor retornado não é relevante. Por isso, usa-se FARPROC. Essa função tem vínculo C.

O valor retornado do auxiliar de carregamento atrasado deve ser armazenado no local do ponteiro da função apresentada, a menos que você queira que a rotina do auxiliar seja usada como gancho de notificação. Nesse caso, seu código é responsável por encontrar o indicador de função adequado para retornar. O código de conversão gerado pelo vinculador usa o valor retornado como destino real da importação e pula diretamente para ele.

## <a name="sample"></a>Amostra

O código a seguir mostra como implementar uma função de gancho simples.

```C
FARPROC WINAPI delayHook(unsigned dliNotify, PDelayLoadInfo pdli)  
{
    switch (dliNotify) {
        case dliStartProcessing :

            // If you want to return control to the helper, return 0.
            // Otherwise, return a pointer to a FARPROC helper function
            // that will be used instead, thereby bypassing the rest
            // of the helper.

            break;

        case dliNotePreLoadLibrary :

            // If you want to return control to the helper, return 0.
            // Otherwise, return your own HMODULE to be used by the
            // helper instead of having it call LoadLibrary itself.

            break;

        case dliNotePreGetProcAddress :

            // If you want to return control to the helper, return 0.
            // If you choose you may supply your own FARPROC function
            // address and bypass the helper's call to GetProcAddress.

            break;

        case dliFailLoadLib :

            // LoadLibrary failed.
            // If you don't want to handle this failure yourself, return 0.
            // In this case the helper will raise an exception
            // (ERROR_MOD_NOT_FOUND) and exit.
            // If you want to handle the failure by loading an alternate
            // DLL (for example), then return the HMODULE for
            // the alternate DLL. The helper will continue execution with
            // this alternate DLL and attempt to find the
            // requested entrypoint via GetProcAddress.

            break;

        case dliFailGetProc :

            // GetProcAddress failed.
            // If you don't want to handle this failure yourself, return 0.
            // In this case the helper will raise an exception
            // (ERROR_PROC_NOT_FOUND) and exit.
            // If you choose you may handle the failure by returning
            // an alternate FARPROC function address.

            break;

        case dliNoteEndProcessing :

            // This notification is called after all processing is done.
            // There is no opportunity for modifying the helper's behavior
            // at this point except by longjmp()/throw()/RaiseException.
            // No return value is processed.

            break;

        default :

            return NULL;
    }

    return NULL;
}

/*
and then at global scope somewhere
PfnDliHook __pfnDliNotifyHook2 = delayHook;
*/
```

## <a name="see-also"></a>Consulte também

[Noções básicas sobre a função auxiliar](../../build/reference/understanding-the-helper-function.md)