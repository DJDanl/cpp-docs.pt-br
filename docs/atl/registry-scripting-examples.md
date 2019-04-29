---
title: Exemplos de scripts do registro
ms.date: 11/04/2016
helpviewer_keywords:
- scripting, examples
- registrar scripts [ATL]
- scripts, Registrar scripts
- registry, Registrar
ms.assetid: b6df80e1-e08b-40ee-9243-9b381b172460
ms.openlocfilehash: dffdd111d33d6fbd845e1534cdef1d5c8e1749d2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62275406"
---
# <a name="registry-scripting-examples"></a>Exemplos de scripts do registro

Os exemplos de scripts neste tópico demonstram como adicionar uma chave ao registro do sistema, registrar o servidor COM registrador e especificar várias árvores de análise.

## <a name="add-a-key-to-hkeycurrentuser"></a>Adicionar uma chave em HKEY_CURRENT_USER

A árvore de análise a seguir ilustra um script simples que adiciona uma única chave de registro do sistema. Em particular, o script adiciona a chave `MyVeryOwnKey`, para `HKEY_CURRENT_USER`. Ele também atribui o valor de cadeia de caracteres de padrão de `HowGoesIt` para a nova chave:

```
HKEY_CURRENT_USER
{
    'MyVeryOwnKey' = s 'HowGoesIt'
}
```

Esse script pode ser estendido facilmente para definir várias subchaves da seguinte maneira:

```
HKCU
{
    'MyVeryOwnKey' = s 'HowGoesIt'
    {
        'HasASubkey'
        {
            'PrettyCool' = d '55'
            val 'ANameValue' = s 'WithANamedValue'
        }
    }
}
```

Agora, o script adiciona uma subchave `HasASubkey`, para `MyVeryOwnKey`. Para essa subchave, ele adiciona ambos os `PrettyCool` subchave (com um padrão `DWORD` valor de 55) e o `ANameValue` valor nomeado (com um valor de cadeia de caracteres de `WithANamedValue`).

##  <a name="_atl_register_the_registrar_com_server"></a> Registrar o servidor de COM do registrador

O script a seguir registra o servidor do registrador COM em si.

```
HKCR
{
    ATL.Registrar = s 'ATL Registrar Class'
    {
        CLSID = s '{44EC053A-400F-11D0-9DCD-00A0C90391D3}'
    }
    NoRemove CLSID
    {
        ForceRemove {44EC053A-400F-11D0-9DCD-00A0C90391D3} = s 'ATL Registrar Class'
        {
            ProgID = s 'ATL.Registrar'
            InprocServer32 = s '%MODULE%'
            {
                val ThreadingModel = s 'Apartment'
            }
        }
    }
}
```

Em tempo de execução, a árvore de análise adiciona o `ATL.Registrar` chave `HKEY_CLASSES_ROOT`. Para essa nova chave, em seguida, it:

- Especifica `ATL Registrar Class` como valor de cadeia de caracteres de padrão da chave.

- Adiciona `CLSID` como uma subchave.

- Especifica `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` para `CLSID`. (Esse valor é o registrador CLSID para uso com `CoCreateInstance`.)

Uma vez que `CLSID` é compartilhado, ele não deve ser removido no modo de cancelar o registro. A instrução `NoRemove CLSID`, é feito indicando que `CLSID` deve ser aberto no modo de registro e ignoradas no modo de cancelar o registro.

O `ForceRemove` instrução fornece uma função de manutenção do sistema, removendo uma chave e todas as suas subchaves antes de criar novamente a chave. Isso pode ser útil se os nomes das subchaves foram alterados. Neste exemplo de script, `ForceRemove` verifica se `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` já existe. Se isso acontecer, `ForceRemove`:

- Exclui de forma recursiva `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` e todas as suas subchaves.

- Recria `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`.

- Adiciona `ATL Registrar Class` como o valor de cadeia de caracteres padrão para `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`.

A árvore de análise agora adiciona duas novas sub-chaves para `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`. A primeira chave, `ProgID`, obtém um valor de cadeia de caracteres padrão que é o ProgID. A segunda chave, `InprocServer32`, obtém um valor de cadeia de caracteres padrão, `%MODULE%`, que é um valor de pré-processador explicado na seção [usando parâmetros substituíveis (pré-processador do registrador The)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md), deste artigo. `InprocServer32` também obtém um valor nomeado, `ThreadingModel`, com um valor de cadeia de caracteres de `Apartment`.

## <a name="specify-multiple-parse-trees"></a>Especifique várias árvores de análise

Para especificar mais de uma árvore de análise em um script, basta colocar uma única árvore no final do outro. Por exemplo, o script a seguir adiciona a chave `MyVeryOwnKey`, as árvores de análise para ambos `HKEY_CLASSES_ROOT` e `HKEY_CURRENT_USER`:

```
HKCR
{
    'MyVeryOwnKey' = s 'HowGoesIt'
}
HKEY_CURRENT_USER
{
    'MyVeryOwnKey' = s 'HowGoesIt'
}
```

> [!NOTE]
> Em um script de registrador, 4K é o tamanho máximo do token. (Um token é qualquer elemento reconhecível na sintaxe). No exemplo de script anterior, `HKCR`, `HKEY_CURRENT_USER`, `'MyVeryOwnKey'`, e `'HowGoesIt'` são todos os tokens.

## <a name="see-also"></a>Consulte também

[Criando scripts do Registrador](../atl/creating-registrar-scripts.md)
