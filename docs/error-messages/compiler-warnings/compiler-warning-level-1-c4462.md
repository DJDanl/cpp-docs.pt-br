---
title: Aviso do compilador (nível 1) C4462
ms.date: 10/25/2017
f1_keywords:
- C4462
helpviewer_keywords:
- C4462
ms.assetid: 4e20aca4-293e-4c75-a83d-961c27ab7840
ms.openlocfilehash: 801a440f131e9428c7f217346a6fd26c72cc1374
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50582319"
---
# <a name="compiler-warning-level-1-c4462"></a>Aviso do compilador (nível 1) C4462

> Não é possível determinar o GUID do tipo. O programa poderá falhar no tempo de execução.

O aviso C4462 ocorre em um aplicativo ou um componente do Tempo de Execução do Windows quando um `TypedEventHandler` público tem como um de seus parâmetros de tipo uma referência para a classe do delimitador.

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para transformar C4462 em um problema de aviso de nível 4, adicione esta linha ao seu arquivo de código de origem:

```cpp
#pragma warning(4:4462)
```

## <a name="example"></a>Exemplo

Este exemplo gera o aviso C4462:

```cpp
namespace N
{
       public ref struct EventArgs sealed {};
       public ref struct R sealed
       {
              R() {}
              event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;
       };
}

[Platform::MTAThread]
int main()
{
     auto x = ref new N::R();
}
```

Existem duas maneiras de resolver o erro. Uma maneira, mostrada no exemplo a seguir, é dar ao evento a acessibilidade interna para que ele esteja disponível para codificar no mesmo executável, mas não para codificar em outros componentes do Tempo de Execução do Windows.

```cpp
internal:
    event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;
```

Se o evento deve ser público, você pode usar outra solução alternativa, que é expor o evento por meio de uma interface padrão:

```cpp
ref struct R;
public interface struct IR{ event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;};

public ref struct R sealed : [Windows::Foundation::Metadata::Default] IR
{
    R() {}
    virtual event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;
};
```

O GUID do tipo `Windows::Foundation::TypedEventHandler<R^, EventArgs^>^` só é usado quando o tipo é acessado de outro componente. A primeira solução alternativa funciona porque só pode ser acessada em seu próprio componente após a solução. Caso contrário, o compilador precisa presumir o pior caso e emitir o aviso.
