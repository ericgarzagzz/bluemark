# BlueMark

A very simple, yet useful transpiler for HTML. BlueMark helps you build HTML user interfaces quickly and declaratively.

# Inspirations

- [Blueprint (GTK)](https://jwestman.pages.gitlab.gnome.org/blueprint-compiler)

# Usage 

```
Html {
    Head {
        Title {
            "Example Domain"
        }

        Meta[http-equiv="Content-type", content="text/html; charset=utf-8"]
        Meta[name="viewport", content="width=device-width, initial-scale=1"]
    }

    Body {
        Div {
            H1 {
                "Example Domain"
            }
            
            P {
                "This domain is for use in illustrative examples in documents.
                You may use this domain in literature without prior coordination or 
                asking for permission."
            }
            
            P {
                A[href="https://www.iana.org/domains/example"] {
                    "More information..."
                }
            }
        }
    }
}
```
