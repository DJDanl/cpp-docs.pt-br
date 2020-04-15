---
title: Usando o dllimport e o dllexport nas classes do C++
ms.date: 11/04/2016
helpviewer_keywords:
- exporting classes [C++]
- declarations [C++], class
- exportable classes [C++]
- classes [C++], declaring
- classes [C++], exportable and inheritance
- inheritance [C++], exportable classes [C++]
- dllimport attribute [C++], classes
- declaring classes [C++]
- dllexport attribute [C++]
- dllexport attribute [C++], classes [C++]
ms.assetid: 8d7d1303-b9e9-47ca-96cc-67bf444a08a9
ms.openlocfilehash: c0a2c96a37f58c956976980beafd5ecbed4d1318
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365114"
---
# <a name="using-dllimport-and-dllexport-in-c-classes"></a>Usando o dllimport e o dllexport nas classes do C++

**Específico da Microsoft**

Você pode declarar classes C++ com o atributo **dllimport** ou **dllexport.** Esses formulários implicam que a classe inteira será importada ou exportada. As classes exportadas dessa maneira são chamadas classes exportáveis.

O exemplo a seguir define uma classe exportável. Todas as suas funções de membro e dados estáticos são exportados:

```cpp
#define DllExport   __declspec( dllexport )

class DllExport C {
   int i;
   virtual int func( void ) { return 1; }
};
```

Observe que é proibido o uso explícito dos atributos **dllimport** e **dllexport** em membros de uma classe exportável.

## <a name="dllexport-classes"></a><a name="_pluslang_using_dllimport_and_dllexport_in_c2b2bdllexportclasses"></a>classes de dllexport

Quando você declara uma **dllexport**de classe, todas as suas funções de membro e membros de dados estáticos são exportados. Você deve fornecer as definições de todos esses membros no mesmo programa. Caso contrário, será gerado um erro de vinculador. A única exceção a essa regra se aplica às funções virtuais puras, para as quais você não precisa fornecer definições explícitas. No entanto, como um destruidor de uma classe abstrata é sempre chamado pelo destruidor da classe base, os destruidores virtuais puros devem fornecer sempre uma definição. Essas regras são as mesmas para classes não exportáveis.

Se você exportar dados do tipo de classe ou de funções que retornarem classes, exporte a classe.

## <a name="dllimport-classes"></a><a name="_pluslang_dllexport_classesdllexportclasses"></a>dllimport Classes

Quando você declara uma **dllimport**de classe, todas as suas funções de membro e membros de dados estáticos são importados. Ao contrário do comportamento de **dllimport** e **dllexport** em tipos não-classe, os membros de dados estáticos não podem especificar uma definição no mesmo programa no qual uma classe **de dllimport** é definida.

## <a name="inheritance-and-exportable-classes"></a><a name="_pluslang_using_dllimport_and_dllexport_in_c2b2binheritanceandexportableclasses"></a>Herança e Classes Exportáveis

Todas as classes base de uma classe exportável devem ser exportáveis. Caso contrário, um aviso do compilador será gerado. Além disso, todos os membros acessíveis que também são classes devem ser exportáveis. Esta regra permite que uma classe **dllexport** herde de uma classe **de dllimport,** e uma classe **de dllimport** para herdar de uma classe **dllexport** (embora esta última não seja recomendada). Como regra, tudo que pode ser acessado pelo cliente da DLL (de acordo com as regras de acesso do C++) deve fazer parte da interface exportável. Isso inclui os membros de dados confidenciais referenciados em funções integradas.

## <a name="selective-member-importexport"></a><a name="_pluslang_using_dllimport_and_dllexport_in_c2b2bselectivememberimportexport"></a>Importação/Exportação de membros seletivos

Como as funções do membro e os dados estáticos dentro de uma classe têm implicitamente linkage externo, você pode declará-los com o atributo **dllimport** ou **dllexport,** a menos que toda a classe seja exportada. Se toda a classe for importada ou exportada, é proibida a declaração explícita das funções e dados dos membros como **dllimport** ou **dllexport.** Se você declarar um membro de dados estático dentro de uma definição de classe como **dllexport,** uma definição deve ocorrer em algum lugar dentro do mesmo programa (como com linkagem externa não-classe).

Da mesma forma, você pode declarar funções de membro com os atributos **dllimport** ou **dllexport.** Neste caso, você deve fornecer uma definição **de dllexport** em algum lugar dentro do mesmo programa.

Vale a pena observar vários pontos importantes sobre a importação e a exportação seletiva de membros:

- A importação/exportação seletiva de membros é melhor usada para o fornecimento de uma versão da interface de classe exportada mais restritiva, isto é, uma para a qual você pode criar uma DLL que exponha menos recursos públicos e particulares do que a linguagem normalmente permitiria. Também é útil para ajustar a interface exportável: quando você souber que o cliente, por definição, não pode acessar alguns dados particulares, não precisará exportar a classe inteira.

- Se você exportar uma função virtual em uma classe, deverá exportar todas elas ou pelo menos fornecer versões que poderão ser diretamente usadas pelo cliente.

- Se você tiver uma classe em que usa a importação/exportação seletiva de membros com funções virtuais, as funções deverão estar na interface exportável ou ser definidas como integradas (podem ser vistas pelo cliente).

- Se você definir um membro como **dllexport,** mas não incluí-lo na definição de classe, um erro de compilador será gerado. Você deve definir o membro no cabeçalho da classe.

- Embora a definição de membros de classe como **dllimport** ou **dllexport** seja permitida, você não pode substituir a interface especificada na definição de classe.

- Se você definir uma função de membro em um lugar diferente do corpo da definição de classe em que você declarou, um aviso será gerado se a função for definida como **dllexport** ou **dllimport** (se essa definição difere da especificada na declaração de classe).

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[dllexport, dllimport](../cpp/dllexport-dllimport.md)
