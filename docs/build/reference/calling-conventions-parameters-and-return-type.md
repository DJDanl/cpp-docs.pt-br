---
title: Convenções de chamada, parâmetros e tipo de retorno
ms.date: 02/13/2019
helpviewer_keywords:
- calling conventions, helper functions
- helper functions, calling conventions
- helper functions, return types
ms.assetid: 0ffa4558-6005-4803-be95-7a8ec8837660
ms.openlocfilehash: 90767141337512b053bb06a40823c4a22a8a4823
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169741"
---
# <a name="calling-conventions-parameters-and-return-type"></a>Convenções de chamada, parâmetros e tipo de retorno

O protótipo de rotina do auxiliar é:

```
FARPROC WINAPI __delayLoadHelper2(
    PCImgDelayDescr pidd,
    FARPROC * ppfnIATEntry
);
```

### <a name="parameters"></a>parâmetros

*pidd*<br/>
Um ponteiro de `const` para uma `ImgDelayDescr` que contém os deslocamentos de vários dados relacionados à importação, um carimbo de data/hora para informações de associação e um conjunto de atributos que fornecem mais informações sobre o conteúdo do descritor. Atualmente, há apenas um atributo, `dlattrRva`, que indica que os endereços no descritor são endereços virtuais relativos. Para obter mais informações, consulte as declarações em *delayimp. h*.

Para obter a definição da estrutura de `PCImgDelayDescr`, consulte [definições de estrutura e constantes](structure-and-constant-definitions.md).

*ppfnIATEntry*<br/>
Um ponteiro para o slot na tabela de endereços de importação de carregamento de atraso (IAT) que é atualizada com o endereço da função importada. A rotina auxiliar precisa armazenar o mesmo valor que ele retorna a esse local.

## <a name="expected-return-values"></a>Valores de retorno esperados

Se a função tiver êxito, ela retornará o endereço da função importada.

Se a função falhar, ela gerará uma exceção e retornará 0. Há três tipos de exceções possíveis:

- Parâmetro inválido, que acontece quando os parâmetros presentes em `pidd` não são especificados corretamente.

- `LoadLibrary` falhou na DLL (biblioteca de vínculo dinâmico) especificada.

- Falha de `GetProcAddress`.

É sua responsabilidade lidar com essas exceções.

## <a name="remarks"></a>Comentários

A convenção de chamada da função do auxiliar é `__stdcall`. O tipo de valor de retorno não é relevante, portanto, FARPROC é usado. Essa função tem vínculo C.

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
const PfnDliHook __pfnDliNotifyHook2 = delayHook;
*/
```

## <a name="see-also"></a>Confira também

[Noções básicas sobre a função auxiliar](understanding-the-helper-function.md)
