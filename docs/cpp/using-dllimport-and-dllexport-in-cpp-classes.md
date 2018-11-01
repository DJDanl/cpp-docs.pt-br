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
ms.openlocfilehash: 3e8545f058043dfbb8abffc86cf987d0315ba3a7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50660753"
---
# <a name="using-dllimport-and-dllexport-in-c-classes"></a>Usando o dllimport e o dllexport nas classes do C++

## <a name="microsoft-specific"></a>Específico da Microsoft

É possível declarar classes C++ com o **dllimport** ou **dllexport** atributo. Esses formulários implicam que a classe inteira será importada ou exportada. As classes exportadas dessa maneira são chamadas classes exportáveis.

O exemplo a seguir define uma classe exportável. Todas as suas funções de membro e dados estáticos são exportados:

```cpp
#define DllExport   __declspec( dllexport )

class DllExport C {
   int i;
   virtual int func( void ) { return 1; }
};
```

Observe que o uso explícito do **dllimport** e **dllexport** atributos em membros de uma classe exportável é proibido.

##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2bdllexportclasses"></a> Classes dllexport

Quando você declara uma classe **dllexport**, todos os seus membros de dados estáticos e funções de membro são exportados. Você deve fornecer as definições de todos esses membros no mesmo programa. Caso contrário, será gerado um erro de vinculador. A única exceção a essa regra se aplica às funções virtuais puras, para as quais você não precisa fornecer definições explícitas. No entanto, como um destruidor de uma classe abstrata é sempre chamado pelo destruidor da classe base, os destruidores virtuais puros devem fornecer sempre uma definição. Essas regras são as mesmas para classes não exportáveis.

Se você exportar dados do tipo de classe ou de funções que retornarem classes, exporte a classe.

##  <a name="_pluslang_dllexport_classesdllexportclasses"></a> Classes DllImport

Quando você declara uma classe **dllimport**, todos os seus membros de dados estáticos e funções de membro são importados. Ao contrário do comportamento de **dllimport** e **dllexport** em tipos sem classe, os membros de dados estáticos não é possível especificar uma definição no mesmo programa no qual um **dllimport** classe é definido.

##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2binheritanceandexportableclasses"></a> Herança e Classes exportáveis

Todas as classes base de uma classe exportável devem ser exportáveis. Caso contrário, um aviso do compilador será gerado. Além disso, todos os membros acessíveis que também são classes devem ser exportáveis. Essa regra permite uma **dllexport** classe para herdar de uma **dllimport** classe e uma **dllimport** classe para herdar de uma **dllexport** classe (embora o último não é recomendado). Como regra, tudo que pode ser acessado pelo cliente da DLL (de acordo com as regras de acesso do C++) deve fazer parte da interface exportável. Isso inclui os membros de dados confidenciais referenciados em funções integradas.

##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2bselectivememberimportexport"></a> Importação/exportação seletiva de membros

Como funções de membro e dados estáticos dentro de uma classe têm implicitamente vinculação externa, você pode declará-las com o **dllimport** ou **dllexport** de atributo, a menos que a classe inteira seja exportada. Se a classe inteira for importada ou exportada, a declaração explícita de funções de membro e dados como **dllimport** ou **dllexport** é proibida. Se você declarar um membro de dados estáticos dentro de uma definição de classe como **dllexport**, deverá ocorrer uma definição em algum lugar dentro do mesmo programa (assim como acontece com ocorre na vinculação externa).

Da mesma forma, você pode declarar funções de membro com o **dllimport** ou **dllexport** atributos. Nesse caso, você deve fornecer um **dllexport** definição em algum lugar dentro do mesmo programa.

Vale a pena observar vários pontos importantes sobre a importação e a exportação seletiva de membros:

- A importação/exportação seletiva de membros é melhor usada para o fornecimento de uma versão da interface de classe exportada mais restritiva, isto é, uma para a qual você pode criar uma DLL que exponha menos recursos públicos e particulares do que a linguagem normalmente permitiria. Também é útil para ajustar a interface exportável: quando você souber que o cliente, por definição, não pode acessar alguns dados particulares, não precisará exportar a classe inteira.

- Se você exportar uma função virtual em uma classe, deverá exportar todas elas ou pelo menos fornecer versões que poderão ser diretamente usadas pelo cliente.

- Se você tiver uma classe em que usa a importação/exportação seletiva de membros com funções virtuais, as funções deverão estar na interface exportável ou ser definidas como integradas (podem ser vistas pelo cliente).

- Se você definir um membro como **dllexport** , mas não incluí-lo na definição de classe, um erro do compilador será gerado. Você deve definir o membro no cabeçalho da classe.

- Embora a definição de membros de classe como **dllimport** ou **dllexport** é permitido, você não pode substituir a interface especificada na definição de classe.

- Se você definir uma função de membro em um local que não seja o corpo da definição de classe em que você declarou, um aviso será gerado se a função é definida como **dllexport** ou **dllimport** (se este definição é diferente do que o especificado na declaração de classe).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[dllexport, dllimport](../cpp/dllexport-dllimport.md)